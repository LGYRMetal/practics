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
-- 语句级触发器
-- 触发器
CREATE OR REPLACE TRIGGER SECURE_EMP
    BEFORE INSERT ON EMP
BEGIN
    IF (TO_CHAR(SYSDATE, 'DY') IN ('星期六', '星期日') OR
        TO_CHAR(SYSDATE, 'HH24:MI') NOT BETWEEN '08:00' AND '18:00') THEN
        -- 提升一条用户自定义的错误信息，通过这个错误信息，中断用户操作
        RAISE_APPLICATION_ERROR(-20500, '你只能在工作时间对表进行操作');
    END IF;

    -- 在触发器中不能使用事务
    --COMMIT;
END;


-- 行级触发器
CREATE OR REPLACE TRIGGER RESTRICT_SALARY
BEFORE INSERT OR UPDATE OF SAL ON EMP
FOR EACH ROW
BEGIN
    IF NOT (:NEW.JOB IN ('AD_PRES', 'AD_VP')) AND :NEW.SAL > 15000 THEN
        RAISE_APPLICATION_ERROR(
            -20202, '员工'|| :NEW.JOB ||'不能赚到' || :NEW.SAL || '的薪水'
        );
    END IF;
END;

-- 新数据 :NEW, 老数据 :OLD
-- 例,不允许降低员工的工资
CREATE OR REPLACE TRIGGER RESTRICT_SALARY
BEFORE UPDATE OF SAL ON EMP
FOR EACH ROW
BEGIN
    -- 新的工资小于老的工资
    IF :NEW.SAL < :OLD.SAL THEN
        RAISE_APPLICATION_ERROR(
            -20202, '你不能降低员工的工资'
        );
    END IF;
END;



-- 练习
-- 创建触发器，解决外键约束问题：在插入员工表记录之前，首先判断新插入的部门
-- 编号是否存在，如果新的部门编号保存在，则首先向部门表中插入该部门
/*
CREATE OR REPLACE TRIGGER INSERT_NEW_DEPT
BEFORE INSERT OR UPDATE OF DEPTNO ON EMP
FOR EACH ROW
BEGIN
    IF :NEW.DEPTNO IS NOT IN (SELECT DEPTNO FROM DEPT) THEN
        INSERT INTO DEPT(DEPTNO) VALUE(:NEW.DEPTNO);
    END IF;
END;
*/
-- 改
CREATE OR REPLACE TRIGGER INSERT_NEW_DEPT
BEFORE INSERT OR UPDATE ON EMP
FOR EACH ROW
DECLARE -- 在触发器中声明变量，必须要加 DECLARE
    V_COUNT NUMBER(4);
    V_DNAME VARCHAR2(10);
BEGIN
    -- 报错,不能在条件里使用子查询: 
    --IF (:NEW.DEPTNO IS NOT IN (SELECT DEPTNO FROM DEPT)) THEN
    SELECT COUNT(*) INTO V_COUNT FROM DEPT WHERE DEPTNO = :NEW.DEPTNO;
    IF (V_COUNT < 1) THEN
        V_DNAME := '部门-' || :NEW.DEPTNO;
        INSERT INTO DEPT(DEPTNO, DNAME, LOC)
        VALUES(:NEW.DEPTNO, V_DNAME, '北京');
    END IF;
END;

-- 练习:
-- 通过触发器，来实现级联删除的操作
-- 在删除部门的时候,如果该部门有员工，把该部门的所有员工也删除掉
CREATE OR REPLACE TRIGGER DELETE_DEPT
BEFORE DELETE ON DEPT
FOR EACH ROW
DECLARE
    V_COUNT NUMBER(2);
BEGIN
    SELECT COUNT(*) INTO V_COUNT FROM EMP WHERE DEPTNO = :OLD.DEPTNO;
    IF (V_COUNT > 0) THEN
        DELETE FROM EMP WHERE DEPTNO = :OLD.DEPTNO;
    END IF;
END;


-- 视图上的 INSTEAD OF 触发器
-- 创建视图
CREATE OR REPLACE VIEW VIEW_EMPINFO
AS
SELECT E.EMPNO, E.ENAME, E.JOB, E.MGR, E.HIREDATE, E.SAL, E.COMM, E.DEPTNO,
       D.DNAME, D.LOC
FROM EMP AS E
JOIN DEPT AS D
ON E.DEPTNO = D.DEPTNO;

-- 从视图中查询数据
SELECT * FROM VIEW_EMPINFO;

-- 创建触发器,把对视图执行的INSERT操作，替换称对表的操作
CREATE OR REPLACE  TRIGGER INSERT_VIEW
    INSTEAD OF VIEW_EMPFINO
    INSERT ON VIEW_EMPINFO
    FOR EACH ROW
DECLARE
    V_COUNT NUMBER(1);
BEGIN
    SELECT COUNT(*) INTO V_COUNT FROM DEPT WHERE DEPTNO = :NEW.DEPTNO;
    -- 判断向视图插入的部门是否存在，如果该部门不存在，则向部门表中插入新
    -- 数据，如果该部门存在，则更新部门表的部门名称和位置
    IF(V_COUNT < 1) THEN
        -- 把一部分数据插入到DEPT表
        INSERT INTO DEPT
        VALUES(:NEW.DEPTNO, :NEW.DNAME, :NEW.LOC);
    ELSE
        UPDATE DEPT SET DNAME=:NEW.DNAME, LOC = :NEW.LOC
        WHERE DEPTNO = :NEW.DEPTNO;
    END IF;

    -- 把一部分数据插入到EMP表
    INSERT INTO EMP
    VALUES(
        :NEW.EMPNO,
        :NEW.JOB,
        :NEW.MGR,
        :NEW.HIREDATE,
        :NEW.SAL,
        :NEW.COMM,
        :NEW.DEPTNO
    );
END;

-- 启用某个触发器
--ALTER TRIGGER trigger_name DISABLE|ENABLE

-- 启用或i禁用某个对象上的所有触发器
--ALTER TABLE table_name DISABLE|ENABLE ALL TRIGGERS

-- 重新编译触发器
--ALTER TRIGGER trigger_name COMPILE

--- 系统级触发器
-- 登陆/退出触发器
-- 创建系统日志表
CREATE TABLE LOGON_TRIG_TABLE(
    USER_ID VARCHAR2(20),
    LOG_DATE DATE,
    ACTION VARCHAR2(255)
);

-- 用户登录之后,自动记录日志
CREATE OR REPLACE TRIGGER LOGON_TRIG
    AFTER LOGON ON SCHEMA
BEGIN
    INSERT INTO LOG_TRIG_TABLE(USER_ID, LOG_DATE, ACTION)
    VALUES(USER, SYSDATE, 'Logging on');
END;

-- 用户退出之前，自动记录日志
CREATE OR REPLACE TRIGGER LOGOFF_TRIG
    BEFORE LOGOFF ON SCHEMA
BEGIN
    INSERT INTO LOG_TRIG_TABLE(USER_ID, LOG_DATE, ACTION)
    VALUES(USER, SYSDATE, 'Logging off');
END;

-- 触发器的作用, 触发器主要用于下列情况
-- 1. 安全性方面，确定用户的操作是否可以继续执行
-- 2. 产生对数据值修改的审计， 将修改的信息记录下来，产生数据改动记录
-- 3. 提供更灵活的完整性校验规则，能根据复杂的规则校验数据
-- 4. 提过表数据的同步复制，使多个表的数据同步
-- 5. 事件日志记录，记录数据库的重要操作
