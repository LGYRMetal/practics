---------------------------- 游标 ------------------------------
-- 在执行增删改查语句的时候，Oracle都会开辟一块内存空间，用来暂时存放受到
-- SQL语句影响的数据,这块内存空间就被称为游标区域，我们可以借助于游标来分析
-- 这些受到影响的数据；

-- 游标的分类:
-- 1. 隐式游标:
--    增删改查语句都会有隐式游标，也就是说，我们可以通过隐式游标来分析受到
--    增删改查语句影响的数据
--
-- 2. 显示游标: 专门用来从数据库中查询多条数据的
--    1. 可用于暂存查询取出的多行结果，然后一行一行的处理
--    2. 显示游标就是专门用来查询多条数据的
--    3. 按行处理查询返回的多行结果
--    4. 显示游标首先将查询出的多行数据暂存在游标区域中，然后在PL/SQL中借助
--       于循环语句手动的控制游标的多行操作，每次取出一条进行处理，直到取出
--       游标中所有的数据为止
--
--    在PL/SQL执行SELECT 语句的特殊要求:
--    1. 必须使用INTO将查询结果存储到变量中
--    2. SELECT 语句必须返回一条记录


-- 游标的属性,游标有四种属性:
-- 1. %ROWCOUNT     受SQL影响的行数
-- 2. %FOUND        Boolean 值，是否还有数据
-- 3. %NOTFOUNTD    Boolean 值，是否已无数据
-- 4. %ISOPEN        游标是否打开
-- 
-- 显示游标和隐式游标都有这四种属性。但使用方法和含义却不相同。
-- 在使用游标的时候，需要使用游标的名称作为前缀。但隐式游标没有名称，所以在
-- 使用隐式游标的时候采用统一的一个名称 SQL。
--     SQL%ROWCOUNT     受SQL影响的行数
--     SQL%FOUND        Boolean值，是否还有数据
--     SQL%NOTFOUND     Boolean值，是否已无数据
--     SQL%ISOPEN       总是为FALSE
-- 示例:
BEGIN
    DELETE FROM EMP WHERE DEPTNO = 10;
    DBMS_OUTPUT.put_line('被删除的数据条数是: ' || SQL%ROWCOUNT);
END;


-- 控制显示游标的过程:
-- 1. 声明游标，创建一个命名的查询语句
-- 2. 打开游标，执行查询语句生成结果集
-- 3. 取出游标中的一条记录装入变量
-- 4. 检测游标中是否还有记录，如果找到记录，返回3，继续取记录,否则，去5
-- 5. 释放游标
--
-- 示例
DECLARE
    -- 1. 声明游标，一个显示游标，就是和一个有效的SELECT语句绑死的
    CURSOR CUR_EMP IS SELECT * FROM EMP;

    V_REC_EMP EMP%ROWTYPE;
BEGIN
    -- 2. 打开游标, 就是执行了游标绑定的SQL语句，并且把受到影响的语句放入
    --    到了游标区域中
    OPEN CUR_EMP; -- 游标在打开之前，和关闭之后,是无法使用的，就会导致无
                  -- 效的游标错误,在关闭之后，如果需要重新使用游标，需要
                  -- 重新打开游标

    -- 3. 取出游标中的一条数据装入记录类型的变量中
    -- 在没有执行FETCH操作之前，游标中是没有数据的,也就是，CUR_EMP%FOUND为
    -- false，所以在进入循环之前要先执行一次 FETCH 操作
    FETCH CUR_EMP INTO V_REC_EMP;

    WHILE(CUR_EMP%FOUND) LOOP
        -- 从记录类型的变量中取出查询数据
        DBMS_OUTPUT.put_line(
            V_REC_EMP.EMPNO || ',' ||
            INITCAP(V_REC_EMP.ENAME) || ',' || 
            V_REC_EMP.JOB   || ',' ||
            V_REC_EMP.MGR   || ',' ||
            V_REC_EMP.HIREDATE || ',' ||
            V_REC_EMP.SAL   || ',' ||
            NVL(V_REC_EMP.COMM, 0)  || ',' ||
            V_REC_EMP.DEPTNO
        );

        -- 3. 取出游标中的一条数据装入记录类型的变量中
        FETCH CUR_EMP INTO V_REC_EMP;

    END LOOP;
    DBMS_OUTPUT.put_line('查询数据的总条数是: ' || CUR_EMP%ROWCOUNT);

    -- 4. 关闭游标,清空游标区域
    CLOSE CUR_EMP;
END;

-- 使用 LOOP循环 和 %NOTFOUND 搭配分析游标数据
-- 示例: 略

-- 使用 FOR循环，可以简化游标的开发，Oracle会自动声明记录类型的变量，自动
-- open, fetch, close 游标
-- 示例:
DECLARE
    -- 1. 声明游标，一个显示游标，就是和一个有效的SELECT语句绑死的
    CURSOR CUR_EMP IS SELECT * FROM EMP;
BEGIN
    -- Oracle会自动的声明记录类型的变量 V_REC_EMP,类型是 EMP%ROWTYPE
    FOR V_REC_EMP IN CUR_EMP LOOP
        -- 从记录类型的变量中取出查询数据
        DBMS_OUTPUT.put_line(
            V_REC_EMP.EMPNO || ',' ||
            INITCAP(V_REC_EMP.ENAME) || ',' || 
            V_REC_EMP.JOB   || ',' ||
            V_REC_EMP.MGR   || ',' ||
            V_REC_EMP.HIREDATE || ',' ||
            V_REC_EMP.SAL   || ',' ||
            NVL(V_REC_EMP.COMM, 0)  || ',' ||
            V_REC_EMP.DEPTNO
        );
    END LOOP;
END;

-------------------------- 存储过程 -------------------------------
CREATE OR REPLACE PROCEDURE CUR_EMP IS
    -- 1. 声明游标，一个显示游标，就是和一个有效的SELECT语句绑死的
    CURSOR CUR_EMP IS SELECT * FROM EMP;

    V_REC_EMP EMP%ROWTYPE;
BEGIN
    -- 2. 打开游标, 就是执行了游标绑定的SQL语句，并且把受到影响的语句放入
    --    到了游标区域中
    OPEN CUR_EMP; -- 游标在打开之前，和关闭之后,是无法使用的，就会导致无
                  -- 效的游标错误,在关闭之后，如果需要重新使用游标，需要
                  -- 重新打开游标

    FETCH CUR_EMP INTO V_REC_EMP;

    WHILE(CUR_EMP%FOUND) LOOP
        -- 从记录类型的变量中取出查询数据
        DBMS_OUTPUT.put_line(
            V_REC_EMP.EMPNO || ',' ||
            V_REC_EMP.ENAME || ',' || 
            V_REC_EMP.JOB   || ',' ||
            V_REC_EMP.MGR   || ',' ||
            V_REC_EMP.HIREDATE || ',' ||
            V_REC_EMP.SAL   || ',' ||
            NVL(V_REC_EMP.COMM, 0)  || ',' ||
            V_REC_EMP.DEPTNO
        );

        -- 3. 取出游标中的一条数据装入记录类型的变量中
        FETCH CUR_EMP INTO V_REC_EMP;

    END LOOP;
    DBMS_OUTPUT.put_line('查询数据的总条数是: ' || CUR_EMP%ROWCOUNT);

    -- 4. 关闭游标,清空游标区域
    CLOSE CUR_EMP;
END;


-- 带参数的游标
DECLARE
    CURSOR CUR(d_no IN emp.deptno%type, min_sal IN emp.sal%type := 1000)
    IS
    SELECT ename, sal, hiredate
    FROM emp WHERE deptno = d_no and sal >= min_sal;
BEGIN
END;
