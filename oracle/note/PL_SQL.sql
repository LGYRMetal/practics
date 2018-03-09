---  PL/SQL中起作用的部分都是有基本块组成的，基本块有四个:
-- 1. 声明部分: DECLARE - 可选部分
--    变量、常量、游标、用户定义异常声明
-- 2. 执行体开始部分: BEGIN - 必要部分
--    SQL 语句
--    PL/SQL 语句
-- 3. 异常处理部分: EXCEPTION - 可选部分
--    程序出现异常时，捕捉异常并处理已异常
-- 4. 执行体结束: END; - 必要部分
--
-- 示例:
DECLARE
    -- 在 DECLARE 部分声明变量，常量等
    -- 声明 变量的规范: 变量名称 变量类型 [:=缺省值]
    V_DEPTNO NUMBER;
BEGIN
    -- 在 BEGIN 部分可以写 SQL语句， PL/SQL语句
    -- 在 BEGIN 部分可以使用 DECLARE 部分声明的变量，常量
    DBMS_OUTPUT.put_line('执行查询语句前, V_DEPTNO=' || V_DEPTNO);

    -- 将查询语句的结果，赋值给 V_DEPTNO 这个变量, PL/SQL 中查询语句必须这样
    SELECT DEPTNO INTO V_DEPTNO FROM EMP WHERE EMPNO = 7369; -- PL/SQL 语句
    DBMS_OUTPUT.put_line('执行查询语句后, V_DEPTNO=' || V_DEPTNO);
    DELETE FROM EMP WHERE DEPTNO = V_DEPTNO; -- SQL 语句
    DELETE FROM DEPT WHERE DEPTNO = V_DEPTNO;
END;


-- 在 PL/SQL 中处理变量
-- 1. 声明部分声明和初始化变量
-- 2. 执行部分为变量赋新值，或在表达式中使用变量
-- 3. 在异常处理部分也可以使用变量
-- 4. 通过参数把值传递到 PL/SQL 块中
-- 5. 通过输出变量或者参数将值传出 PL/SQL 块


-- 在SQL命令行中执行 PL/SQL 代码，在代码的最后必须加一个 /

-- Oracle 中的数据类型分为:
-- 1. 基本数据类型变量(也称简单变量): 简单变量不包括任何组件，只能保存一个值
--    基本变量包括三大类: 字符，数字，日期
--      BINARY_INTEGER 整形数字
--      NUMBER[(precision, scale)] 数字类型
--      CHAR[(maximum_length)] 定长字符类型
--      VARCHAR2(maximum_length) 边长字符类型
--      DATE 日期类型
--      LONG 长字符类型
--      LONG RAW 长二进制类型
--      CLOB/BLOB/BFILE 大对象类型(字符/二进制/操作系统文件 大对象)
--      BOOLEAN 布尔类型
-- 2. 复合数据类型: 复合变量也叫组合变量，在复合变量中包含多个内部的组件，
--    每个组件都可以单独存放值，一个复合变量可以存放多个值
--    与简单变量类型不同，复合变量类型不是数据库中已经存在的数据类型，所以
--    复合变量在声明类型之前，首先要创建使用到的复合类型，然后将变量声明为
--    复合变量
--    复合数据类型：
--      PL/SQL TABLES 表类型, 索引从 1 开始, 类似于java的数组和Map
--          声明表类型:
DECLARE
    --  在 DECLARE 部分声明表类型
    TYPE NAMEED_TABLE_TYPE IS TABLE OF VARCHAR2(20) INDEX BY BINARY_INTEGER;

    -- 使用声明的表类型来声明变量
    V_TABLE NAMEED_TABLE_TYPE;
BEGIN
    -- 给表类型的变量赋值，可以通过索引来访问表类型的变量
    -- 表类型的变量没有长度的限制
    V_TABLE(1) := 'Hello1';
    V_TABLE(2) := 'Hello2';
    V_TABLE(3) := 'Hello3';
    V_TABLE(4) := 'Hello4';
    V_TABLE(5) := '工程师';

    DBMS_OUTPUT.put_line(
        'V_TABLE1='  || V_TABLE(1) ||
        ',V_TABLE2=' || V_TABLE(2) ||
        ',V_TABLE3=' || V_TABLE(3) ||
        ',V_TABLE4=' || V_TABLE(4) ||
        ',V_TABLE5=' || V_TABLE(5) 
    );
END;
--      PL/SQL RECORDS 记录类型
--          类似于java的 实体类, 或 更类似于数据库的表
DECLARE
    -- 声明记录类型
    TYPE NAMED_RECORE_TYPE IS RECORD (
        EMPNO NUMBER(4),
        ENAME VARCHAR2(20),
        JOB VARCHAR2(20),
        MGR NUMBER(4),
        HIREDATE DATE,
        SAL NUMBER(8,2),
        COMM NUMBER(8,2),
        DEPTNO NUMBER(4)
    );

    -- 使用记录类型声明变量
    V_REC NAMED_RECORE_TYPE;
BEGIN
    -- 给记录类型的变量赋值
    V_REC.EMPNO := 7936;
    V_REC.ENAME := '张三';
    V_REC.JOB := '工程师';
    V_REC.MGR := 7800;
    V_REC.HIREDATE := TO_DATE('1986-12-6', 'YYYY-MM-DD');
    V_REC.SAL := 2000;
    V_REC.COMM := 1000;
    V_REC.DEPTNO := 10;

    DBMS_OUTPUT.put_line(
        'V_REC.EMPNO=' || V_REC.EMPNO ||
        ',V_REC.ENAME=' || V_REC.ENAME ||
        ',V_REC.JOB=' || V_REC.JOB   ||
        ',V_REC.MGR=' || V_REC.MGR   ||
        ',V_REC.HIREDATE=' || TO_CHAR(V_REC.HIREDATE, 'YYYY-MM-DD') ||
        ',V_REC.SAL=' || V_REC.SAL ||
        ',V_REC.COMM=' || V_REC.COMM||
        ',V_REC.DEPTNO=' || V_REC.DEPTNO
    );
END;
--      复合类型被创建后，可以被使用多次定义多个变量


-- 使用 %type 来声明变量
-- 除了可以使用已经确定的类型来声明变量之外，还可以使用 %type，%rowtype
-- 来作为变量的类型
-- 当我们用 %type 来声明变量的时候，我们声明的变量可以是简单类型，也可以是
-- 表类型
-- %type 的前缀可以是一个前面已经声明过的简单类型的变量(可以是简单类型，
-- 也可以是表类型)，也可以是一个表的
-- 字段的名称
DECLARE
    V_EMPNO NUMBER(4);
    V_DEPTNO V_EMPNO%TYPE; -- 用 V_EMPNO 的类型作为 V_DEPTNO 的类型
BEGIN
    V_EMPNO := 8000;
    V_DEPTNO := 20;
    DBMS_OUTPUT.put_line(
        'V_EMPNO=' || V_EMPNO || ', V_DEPTNO=' ||  V_DEPTNO
    );
END;

-- 使用表的字段类型来声明变量
DECLARE
    V_DEPTNO EMP.ADDR%TYPE; -- 用EMP表的 ADDR 的类型作为V_DEPTNO的类型，当
                            -- EMP表的类型变化的时候，V_DEPTNO的类型自动
                            -- 跟着变化
BEGIN
    V_DEPTNO := 'aaaaaaaaaaaaaaaa'
    DBMS_OUT_put_line('V_DEPTNO=' || V_DEPTNO);
END;


-- %ROWTYPE 声明的肯定是记录类型的变量，并且会跟着b参照表的变化而变化
-- %ROWTYPE 的前缀，可以是一个表名，也可以是前面声明的一个记录类型的变量(
-- 该变量不行要参照于一个表，而不能是自定义的记录类型)
DECLARE
    -- %ROWTYPE 的前缀是一个表名
    -- 使用 %ROWTYPE 的时候，Oracle 做了两件事情
    -- 1. 用DEPT表的字段及其类型声明了一种记录类型
    -- 2. 用这种记录类型声明变量
    V_EMP DEPT%ROWTYPE;
BEGIN
    V_EMP.DEPTNO := 30;
    V_EMP.DNAME := '开发部';
    V_EMP.LOC := '北京';
    DBMS_OUTPUT.put_line(
        'V_EMP.DEPTNO='  || V_EMP.DEPTNO ||
        ', V_EMP.DNAME=' || V_EMP.DNAME  ||
        ', V_EMP.LOC='   || V_EMP.LOC
    );
END;

DECLARE
    -- V_DEPT 是一种记录类型的变量
    V_DEPT DEPT%ROWTYPE;
    V_EMP V_DEPT%ROWTYPE; -- 用 V_DEPT 的类型(记录类型)来作为 V_EMP 的类型
                          -- V_EMP 也是一种记录类型
BEGIN
    V_EMP.DEPTNO := 30;
    V_EMP.DNAME := '开发部';
    V_EMP.LOC := '北京';
    DBMS_OUTPUT.put_line(
        'V_EMP.DEPTNO='  || V_EMP.DEPTNO ||
        ', V_EMP.DNAME=' || V_EMP.DNAME  ||
        ', V_EMP.LOC='   || V_EMP.LOC
    );
END;


-- PL/SQL 标识符规定
-- 1. 最多可以包含30个字符
-- 2. 不能包含保留字，若有使用双引号括起来
-- 3. 必须以字母字符开始
-- 4. 不能与数据库表或者列名相同


-- USER 会返回当前登陆的用户的名称, 就像SYSDATE返回当前系统时间一样


-- 在PL/SQL中执行DDL, DCL要使用 EXECUTE IMMEDIATE
BEGIN
    EXECUTE IMMEDIATE
    'CREATE TABLE USERS (
        ID NUMBER(4) PRIMARY KEY,
        NAME VARCHAR2(20),
        SEX CHAR(2)
    )';
END;

BEGIN
    EXECUTE IMMEDIATE
    'DROP TABLE USERS';
END;

-- 如果 EXECUTE IMMEDIATE 中的双引号中的语句也包含双引号，那么把一个双引号
-- 改成两个双引号,但不能使用双引号



-- LOOP 循环
DECLARE
    V_COUNT NUMBER(3) := 1; -- 初始条件
BEGIN
    LOOP
        DBMS_OUTPUT.put_line('V_COUNT=' || V_COUNT);
        V_COUNT := V_COUNT + 1;
        EXIT WHEN V_COUNT > 10;
    END LOOP;
END;


-- WHILE 循环
DECLARE
    V_COUNT NUMBER(3) := 1;
BEGIN
    WHILE (V_COUNT <= 10) LOOP
        DBMS_OUTPUT.put_line('V_COUNT=' || V_COUNT);
        V_COUNT := V_COUNT + 1;
    END LOOP;
END;


-- FOR 循环, 在使用FOR循环的时候，由Oracle维护计数器
BEGIN
    -- Oracle 会自动声明计数器，会自动进行计数器的迭代
    FOR V_COUNT IN 1..100 LOOP
        DBMS_OUTPUT.put_line('V_COUNT=' || V_COUNT);
    END LOOP;
END;

-- 倒序
BEGIN
    -- Oracle 会自动声明计数器，会自动进行计数器的迭代
    FOR V_COUNT IN REVERSE 1..100 LOOP
        DBMS_OUTPUT.put_line('V_COUNT=' || V_COUNT);
    END LOOP;
END;
