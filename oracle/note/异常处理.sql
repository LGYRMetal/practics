-- 在PL/SQL中出现的异常，如果没有处理，异常会被传递给调用环境，中断程序执行
-- PL/SQL 程序会从发生异常的代码处中断，以后的代码是无法执行的
-- 当PL/SQL程序中，在BEGIN部分中的语句引起异常之后，就会进入到EXCEPTION部分
-- 执行异常处理功能
-- 当PL/SQL中出现的异常，我们采取了措施之后，就不会产生错误信息了
-- Oracle中的异常类型分为三类:
--   1. 预定义异常，Oracle已经为这种异常定义好多了名称，我们在异常处理部分
--      直接通过异常名称进行捕获
DECLARE
    V_JOB EMP.JOB%TYPE;
BEGIN
    SELECT JOB INTO V_JOB FROM EMP WHERE EMPNO = 8001;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.put_line('执行的SELECT语句没有查询到结果');
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.put_line('执行的SELECT语句不能查询多条结果');
    WHEN INVALID_CURSOR THEN
        DBMS_OUTPUT.put_line('无效的游标');
    WHEN ZERO_DIVIDE THEN
        DBMS_OUTPUT.put_line('不能把0作为分母');
    WHEN DUP_VAL_ON_INDEX THEN
        DBMS_OUTPUT.put_line('唯一索引中插入重复值,违反主键约束');
    WHEN VALUE_ERROR THEN
        DBMS_OUTPUT.put_line('赋值异常');
    WHEN OTHERS THEN -- 捕获其他所有未被捕获的异常
        DBMS_OUTPUT.put_line('PL/SQL中发生了其他异常');
END;

--   2. 非预定义异常，也是因为违反了Oracle的规则，Oracle会产生报错信息(有
--      报错编号和报错信息),但是Oracle并没有为这类错误定义好异常名称,那么
--      我们可以自己定义一个异常名称，并将这个异常名称和异常编号绑定
DECLARE
    E_MYEXCEPTION EXCEPTION; -- 自己定义一个异常名称
    PRAGMA EXCEPTION_INIT(E_MYEXCEPTION, -02292); -- 将异常名称和异常编号
                                                  -- 绑定
BEGIN
    DELETE FROM DEPT WHERE DEPTNO = 10;
EXCEPTION
    WHEN E_MYEXCEPTION THEN
        DBMS_OUTPUT.put_line('违反外键约束');
    WHEN OTHERS THEN -- 捕获其他所有未被捕获的异常
        DBMS_OUTPUT.put_line('PL/SQL中发生了其他异常');

END;

--   3. 用户定义的异常,错做的时候，并没有违反Oracle的规则，但违反了用户定义
--      的规则，由于没有违反Oracle的规则，Oracle不会自己主动的产生报错信息，
--      需要我们自己手动的提升一个异常
CREATE TABLE SM_EMP(
    NO CHAR(4),
    NAME CHAR(10),
    SALARY NUMBER(6,2),
    PHONE CHAR(8)
);
-- INSERT TOM
INSERT INTO SM_EMP VALUES ('001', 'TOM', '999.99', '62543678');
INSERT INTO SM_EMP VALUES ('002', 'TOM', '999.99', '62543678');
INSERT INTO SM_EMP VALUES ('003', 'TOM3', '999.99', NULL);

COMMIT;

DECLARE
    V_NAME VARCHAR2(20);
    E_PHONE_LOST_EXCEPTION EXCEPTION; -- 自定义一个异常
    CURSOR CUR_SM_EMP IS SELECT * FROM SM_EMP;
BEGIN
    FOR V_REC_EMP IN CUR_SM_EMP LOOP
        IF (V_REC_EMP.PHONE IS NULL) THEN
            V_NAME := V_REC_EMP.NAME;
            -- 当判断到违反了用户的规则，需要自己提升一个异常
            RAISE E_PHONE_LOST_EXCEPTION;
        END IF;
    END LOOP;
EXCEPTION
    WHEN E_PHONE_LOST_EXCEPTION THEN
        DBMS_OUTPUT.put_line(V_NAME || '的电话为NULL');
    WHEN OTHERS THEN
        DBMS_OUTPUT.put_line('PL/SQL发生其他异常');
END;
DROP TABLE SM_EMP;

-- 注意：预定义异常和非预定义异常都是因为违反了Oracle的规则，Oracle会自动的
-- 产生异常，而用户定义的异常并没有违反Oracle的规则，Oracle 不会自动的产生
-- 异常，需要自己手动RAISE异常

-- 对于非预测的异常，如何处理?
-- 用 WHEN OTHERS THEN 捕获所有的非预期的异常，取到错误编号和错误信息，记录
-- 到数据库中
DROP TABLE ERR_LOG;
DROP SEQUENCE SEQ_ERRLOG;
CREATE TABLE ERR_LOG (
    ID NUMBER(5) PRIMARY KEY,
    CODE NUMBER(10),
    MESSAGE VARCHAR2(255),
    DATETIME DATE
);
-- 创建序列
CREATE SEQUENCE SEQ_ERRLOG
MINVALUE 1
MAXVALUE 99999
START WITH 1
INCREMENT BY 1;

DECLARE
    V_CODE NUMBER(10);
    V_MSG VARCHAR2(255);
BEGIN
    DELETE FROM DEPT WHERE DEPTNO = 10;
EXCEPTION
    WHEN OTHERS THEN
        V_CODE := SQLCODE; -- 获取错误编号
        V_MSG := SQLERRM; -- 获取错误信息

        -- 把错误编号和错误信息插入到日志表中
        INSERT INTO ERR_LOG
        VALUES(SEQ_ERRLOG.NEXTVAL, V_CODE, V_MSG, SYSDATE);
        COMMIT;
        DBMS_OUTPUT.put_line(
            'PL/SQL程序中遇到异常，请查询日志表获取详细信息'
        );
END;

DROP TABLE ERR_LOG;
DROP SEQUENCE SEQ_ERRLOG;
