---------------------- PL/SQL程序单元 ----------------------------
-- PL/SQL程序，也叫PL/SQL程序单元，是数据库中命名的PL/SQL块
-- 主要有四类:
--   1. 过程: 执行特定操作
--   2. 函数: 进行复杂计算，返回计算的结果
--   3. 包: 将逻辑上相关的过程和函数组织在一起
--   4. 触发器: 事件触发，执行相应操作

-- 调用过程:
--   1. 在命令行中
--      EXEC 过程名; -- 需要 SET SERVEROUTPUT ON;才可以看到输出结果
--   2. 在匿名块中调用
--      BEGIN
--          过程名;
--      END;


--- 创建带有参数的存储过程
CREATE OR REPLACE PROCEDURE ADD_DEPT(P_DEPTNO NUMBER,
                            P_DNAME VARCHAR2,
                            P_LOC VARCHAR2)
IS
BEGIN
    INSERT INTO DEPT
    VALUES (P_DEPTNO, P_DNAME, P_LOC);
END;

-- 在匿名块中调用存储过程
-- 调用有参数的过程的不同方式
-- 1. 按参数名称调用, 参数顺序可以不按声明顺序
DECLARE
    V_DEPTNO NUMBER(4) := 50;
    V_DNAME VARCHAR2(20) := '销售部';
    V_LOC VARCHAR2(10) := '北京';
BEGIN
    ADD_DEPT(P_DEPTNO => V_DEPTNO, P_DNAME => V_DNAME, P_LOC => V_LOC);
    --ADD_DEPT(P_DNAME => V_DNAME, P_DEPTNO => V_DEPTNO, P_LOC => V_LOC);
END;

-- 2. 按参数位置调用, 顺序必须和声明时的参数顺序一致
DECLARE
    V_DEPTNO NUMBER(4) := 50;
    V_DNAME VARCHAR2(20) := '销售部';
    V_LOC VARCHAR2(10) := '北京';
BEGIN
    ADD_DEPT(V_DEPTNO, V_DNAME, V_LOC);
END;

-- 3. 按照混合方式调用
DECLARE
    V_DEPTNO NUMBER(4) := 50;
    V_DNAME VARCHAR2(20) := '销售部';
    V_LOC VARCHAR2(10) := '北京';
BEGIN
    ADD_DEPT(V_DEPTNO, P_LOV => V_LOC, P_DNAME = >V_DNAME);
END;


-- 作为oracle中过程中的参数，处理有数据类型之外，还有一种特殊的类型，即
-- 输入输出类型(IN, OUT, IN OUT), 在未指明的情况下，默认是 IN 类型
CREATE OR REPLACE PROCEDURE PARAM_TEST(P_IN IN VARCHAR2,
                             P_OUT OUT VARCHAR2,
                             P_IN_OUT IN OUT VARCHAR2)
IS
BEGIN
    DBMS_OUTPUT.put_line('在过程中，P_IN=' || P_IN);
    DBMS_OUTPUT.put_line('在过程中，P_OUT=' || P_OUT);
    DBMS_OUTPUT.put_line('在过程中，P_IN_OUT=' || P_IN_OUT);

    -- 作为 OUT 类型的参数，可以在过程中被重新赋值，并会被返回给调用者
    P_OUT := 'OUT类型的参数在过程中被重新赋值';
    P_IN_OUT := 'IN OUT类型的参数在过程中被重新赋值';
END;

-- 
DECLARE
    V_IN VARCHAR2(100) := 'IN 类型参数的初始值';
    V_OUT VARCHAR2(100) := 'OUT 类型参数的初始值';
    V_IN_OUT VARCHAR2(100) := 'IN OUT 类型参数的初始值';
BEGIN
    PARAM_TEST(V_IN, V_OUT, V_IN_OUT);

    DBMS_OUTPUT.put_line('在过程外，P_IN=' || P_IN);
    DBMS_OUTPUT.put_line('在过程外，P_OUT=' || P_OUT);
    DBMS_OUTPUT.put_line('在过程外，P_IN_OUT=' || P_IN_OUT);
END;



----------------------------- 函数 -----------------------------
-- 函数，可以接受一个或多个参数，在函数中完成运算，最终返给用户一个结果(
-- Oracle中的函数必须又返回结果)
-- 根据职位和薪金计算佣金的值
-- 函数的参数也有输入输出类型，但OUT类型的参数使用不方便，所以在函数中只
-- 使用IN类型的参数
CREATE OR REPLACE FUNCTION ADD_COMM(P_JOB VARCHAR2, P_SAL EMP.SAL%TYPE)
RETURN NUMBER
IS
    V_COMM EMP.COMM%TYPE;
BEGIN
    IF(P_JOB = 'CLERK') THEN
        V_COMM := P_SAL * 0.5;
    ELSIF(P_JOB = 'SALESMAN') THEN
        V_COMM := P_SAL * 0.6;
    ELSIF(P_JOB = 'PRESIDENT') THEN
        V_COMM := P_SAL * 0.7;
    ELSIF(P_JOB = 'ANALYST') THEN
        V_COMM := P_SAL * 0.8;
    ELSE
        V_COMM := P_SAL * 1.0;
    END IF;

    RETURN V_COMM; -- 在函数中一定要有一个有效的 RETURN 语句
END;

-- 调用函数
-- 1. 无法在命令行中调用函数,不能单独执行
-- 2. 在匿名块中调用函数
DECLARE
    V_RES NUMBER(8);
    V_STR VARCHAR2(20) := '字符串';
    V_LENGTH NUMBER(3);
BEGIN
    V_RES := ADD_COMM('SALESMAN', 2000);
    V_LENGTH := LENGTH(V_STR);
    DBMS_OUTPUT.put_line('V_RES = ' || V_RES);
    DBMS_OUTPUT.put_line('V_LENGTH = ' || V_LENGTH);
END;

-- 3. 在SQL语句中使用函数
SELECT ENAME, LENGTH(ENAME) "名字长度", JOB, SAL, ADD_COMM(JOB, SAL) "佣金"
FROM EMP;



----------------------------- 包 -----------------------------
BEGIN
    DBMS_OUTPUT.put_line('aaa'); -- DBMS_OUTPUT就是一个包
END;



-------------------------------- 触发器 ---------------------------
-- 触发器
CREATE OR REPLACE TRIGGER SECURE_EMP
    BEFORE INSERT ON EMP
BEGIN
    IF (TO_CHAR(SYSDATE, 'DY') IN ('星期六', '星期日') OR
        TO_CHAR(SYSDATE, 'HH24:MI') NOT BETWEEN '08:00' AND '18:00') THEN
        -- 提升一条用户自定义的错误信息，通过这个错误信息，中断用户操作
        RAISE_APPLICATION_ERROR(-20500, '你只能在工作时间对表进行操作');
    END IF;
END;
