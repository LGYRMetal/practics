-- Oracle中的主要数据类型
--     1. 字符型
--        VARCHAR(10) 定长的字符型数据
--        CHAR(2)     定长的字符型数据
--        VARCHAR2(20) 变长的字符型数据
--     2. 数值型
--        NUMBER(4) 不带小数点的数值型数据
--        NUMBER(8,2) 带小数点的数值型数据
--     3. 日期型
--        DATE


-- 删除表的语句
DROP TABLE USERS;

-- 创建表的语句
CREATE TABLE USERS(
    ID       NUMBER(4) PRIMARY KEY,
    NAME     VARCHAR(10),
    PASSWORD VARCHAR2(10),
    SEX      CHAR(2),
    ADDR     VARCHAR2(20),
    BIRTHDAY DATE,
    SAL      NUMBER(8,2)
);

-- 查看表的结构，但只能在命令行模式下使用
DESC USERS;

-- SQL语句不区分大小写，包括登录的用户名，密码也不区分大小写

-- 在查询过程中，对于数值型的数据，可以执行 +, -, *, / 运算

-- 可以给查询字段起别名，有不同的方式，双引号可选，as也可选，例
SELECT EMPNO 员工编号,ENAME 员工姓名,SAL "月薪",SAL*12 AS "年薪"
FROM EMP;

-- 在算数表达式中出现NULL,得到的结果就是NULL,NULL不等于0.0

-- 用 || 可以将两列或多列查询结果合并到一起, 例:
SELECT EMPNO,ENAME,JOB,EMPNO||ENAME||JOB "员工信息"
FROM EMP;

-- 在连接表达式中出现字符数据
-- 在连接表达式中出现NULL，就是原来的字符型数据
SELECT EMPNO || ' 的经理是 ' || MGR AS "从属关系"
FROM EMP;

-- 任何的类型都支持NULL(空值)

-- PL/SQL中对数据进行修改，可以在使用下面的select语句后，直接在查询结果集中
-- 修改
SELECT * FROM EMP
FOR UPDATE;

-- 对于日期型的数据可以使用 +, - 运算符
-- 1. 一个日期 + - 一个数值(就是 + - 一个天数)，得到一个新的日期，例
SELECT EMPNO,ENAME,HIREDATE "雇佣日期", (HIREDATE + 90) "转正日期"
FROM EMP;

-- 2. 两个日期型的数据相减，得到的是两者之间相差的天数,例
SELECT EMPNO,ENAME, (SYSDATE - HIREDATE)/365 "工作的年限"
FROM EMP;
-- SYSDATE 取得当前的日期

-- 3. 两个日期型的数据不能相加，日期型的数据不能进行乘除运算

-------------------------------------------------------------
-- 去除单列重复的数据
SELECT DISTINCT DEPTNO
FROM EMP;

-- 去除多列重复的数据
SELECT DISTINCT JOB, DEPTNO
FROM EMP;

--------------------------------------------------------------
-- 使用WHERE子句对数据进行过滤
SELECT *
FROM EMP
WHERE DEPTNO = 10;

-- 对于字符型的数据和日期型的数据必须要使用 ''
-- 字符型的数据对大小写是敏感的
SELECT *
FROM EMP
WHERE ENAME = 'SMITH';

-- 日期型的数据，格式是敏感的，使用日期型数据的默认格式是
-- DD-MM-YYYY(日-月-年)
-- 如果是中文版的Oracle，那么必须要在月份里加一个‘月’,英文版不需要
SELECT *
FROM EMP
WHERE HIREDATE = '20-2月-1981';

-- 改变当前会话中的日期格式
alter session set nls_date_format="YYYY-MM-DD HH:MI:SS";

-- 使用BETWEEN ... AND，会包含边界的
SELECT *
FROM EMP
WHERE SAL BETWEEN 2000 AND 3000;
-- 在结果中会包含SAL是2000和3000的结果,相当于
SELECT *
FROM EMP
WHERE SAL >= 2000 AND SAL <= 3000;

-- 使用IN
SELECT *
FROM EMP
WHERE JOB IN('MANAGER', 'CLERK');
-- 相当于
SELECT *
FROM EMP
WHERE JOB = 'MANAGER' OR JOB = 'CLERK';

-- LIKE 用于字符型数据的查询，可以执行模糊查询
-- % 表示零个或多个任意的字符
SELECT *
FROM EMP
WHERE ENAME LIKE '%A%';

-- _ 表示一个任意字符
SELECT *
FROM EMP
WHERE ENAME LIKE '_A%';

-- 对于空值要使用 IS NULL 进行比较
SELECT *
FROM EMP
WHERE COMM IS NULL;

-- 使用NOT运算符
SELECT *
FROM EMP
WHERE SAL NOT BETWEEN 2000 AND 3000;
-- 相当于
SELECT *
FROM EMP
WHERE SAL < 2000 OR SAL > 3000;

-- SQL注入攻击, 由于NOT，AND，OR的运算优先级是 NOT>AND>OR，所以，即使用户
-- 输入的密码不对，也可以查出想要的数据
SELECT *
FROM USERS
WHERE NAME = 'admin' OR 'X'='X' AND PASSWORD='43423';

-----------------------------------------------------------------------
-- 对查询后的数据进行排序,使用ORDER BY 子句,默认使用指定的字段升序排序
SELECT *
FROM EMP
WHERE SAL > 2000
ORDER BY SAL;

-- 显示的指定升降序
-- 1. 升序
SELECT *
FROM EMP
WHERE SAL > 2000
ORDER BY SAL ASC;

-- 2. 降序
SELECT *
FROM EMP
WHERE SAL > 2000
ORDER BY SAL DESC;

-- 也可以使用字段的别名进行排序
SELECT EMPNO, ENAME, (SAL * 12) "年薪"
FROM EMP
ORDER BY "年薪";

-- 使用多个字段排序
SELECT *
FROM EMP
WHERE SAL > 2000
ORDER BY DEPTNO, SAL;
------------------------------------------------------------------------

-- 转义特出字符, ESCAPKE 是指定转移符
SELECT *
FROM EMP
WHERE ENAME LIKE '%\%%' ESCAPE '\';
