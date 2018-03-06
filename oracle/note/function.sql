------------------------ Oracle中的函数 ----------------------------
-- INITCAP(c1)
-- 返回字符串并将字符串的第一个字母变为大写，其他字母小写
-- 参数：c1 字符型表达式
SELECT INITCAP(ENAME) "姓名"
FROM EMP;

-- 四舍五入
SELECT ROUND(45.943, 2) "小数点后两位",
       ROUND(45.943, 0) "个位",
       ROUND(45.943, -1) "十位"
FROM SYS.DUAL;
-- 注意，是 FROM SYS.DUAL

-- 当前系统时间，Oracle默认的显示时间格式
SELECT SYSDATE
FROM SYS.DUAL;
-- 但Oracle时间默认的使用格式是DD-MM-YYYY(日-月-年)

-- TO_NUMBER, 把字符性的数据转为数值，字符的格式和模板的模式必须一致
-- 例如，要是前面是美元符合，就必须都是美元符号
SELECT TO_NUMBER('$800.00', '$999,999.00')
FROM SYS.DUAL;

-- 在算数表达式中出现NULL，得到的结果就是NULL，可以用NVL()函数解决
SELECT (SAL * 12 + NVL(COMM, 0)) "年收入"
FROM EMP;
-- 替代的数据和被替代的数据的数据类型必须一致
SELECT NVL(JOB, '还没有工作')
FROM EMP;

-- COUNT有两种用法
-- 1.count(*) 查询数据的总条数
SELECT COUNT(*) "记录总数"
FROM EMP;

-- 2.count(字段), 这种情况下，忽略空值
SELECT COUNT(COMM)
FROM EMP;
-- 所有的组函数都是忽略空值的
SELECT SUM(COMM) "总和", AVG(COMM) "平均值", COUNT(COMM) "有佣金的人数"
FROM EMP;

-- 对数据进行分组后，使用组函数
-- 1. 出现在查询列表中的字段，要么出现在组函数中，要么出现在 GROUB BY 中
-- 2. 也可以只出现在 GROUP BY 中

-- 要对分组后的数据进行过滤，不能使用 WHERE 子句，而要用 HAVING 子句
SELECT DEPTNO, MAX(SAL)
FROM EMP
GROUP BY DEPTNO
HAVING MAX(SAL) >= 3000
ORDER BY DEPTNO;

-- 首先用 WHERE 对数据过滤，过滤后的数据用 GROUP BY 分组，分组后的数据用
-- HAVING再过滤，过滤后的数据用 ORDER BY 排序
SELECT DEPTNO, MAX(SAL)
FROM EMP
WHERE DEPTNO IS NOT NULL
GROUP BY DEPTNO
HAVING MAX(SAL) >= 3000
ORDER BY DEPTNO;

-- 组函数也可以嵌套
-- 但是，在组函数嵌套的时候，必须要使用 GROUP BY
-- 组函数最多嵌套两层
SELECT MAX(MAX(SAL))
FROM EMP
WHERE DEPTNO IS NOT NULL
GROUP BY DEPTNO;
