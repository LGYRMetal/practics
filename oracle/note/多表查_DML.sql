-------------------------- 多表查询 ------------------------
-- SQL92 外连接
-- 1. 左外连接，可以把右边表中不满足等值条件的数据查询出来
SELECT E.EMPNO, E.ENAME, E.DEPTNO, D.DEPTNO, D.DNAME
FROM EMP E, DEPT D
WHERE D.DEPTNO (+) = E.DEPTNO;

-- 2. 右外连接，可以把左边表中不满足等值条件的数据查询出来
SELECT E.EMPNO, E.ENAME, E.DEPTNO, D.DEPTNO, D.DNAME
FROM EMP E, DEPT D
WHERE D.DEPTNO = E.DEPTNO (+);

-- (+) 不能同时出现在 = 两边


-- SQL99
-- 1. 交叉连接,相当于SQL92中，没有给出等值条件的情况，会产生笛卡尔积
SELECT E.*, D.*
FROM EMP E
CROSS JOIN DEPT D;

-- 2. 自然连接，在父子表关系上，自动匹配两个表中列名完整相同的字段(参照列)，--    在这些相同名称的字段上做等值查询
--    参照列上不能使用前缀, 如 DEPTNO
--    当两个表中没有参照列的时候，自然链接会产生笛卡尔积
--
--    自然链接的缺陷：
--      1. 自然链接会把所有的参照列都作为等值条件，自作多情
--      2. 如果参照列的类型不同，查询汇报做
SELECT E.EMPNO, E.ENAME, DEPTNO, D.DNAME
FROM EMP E
NATURAL JOIN DEPT D;

--      3. JOIN ...USING，在自然链接的基础上，加以改进，使用指定的参照列
--         来作为等值条件
SELECT E.EMPNO, E.ENAME, DEPTNO, D.DNAME
FROM EMP E
JOIN DEPT D USING(DEPTNO)
WHERE E.EMPNO = 7369;



-- 使用查询语句来创建表(复制表及其数据，但并没有复制主外键)
CREATE TABLE DEPT_BAK
AS
SELECT * FROM DEPT;



-- 使用UNION把两个结果集合并成一个结果集，两个结果集必须一致
--   结果集一致，指的是，查询字段的个数，查询字段的类型，查询字段的顺序
--   必须一致
-- UNION, 会去除重复的数据
-- UNION ALL，不去除重复的数据


-- 子查询没有结果，主查询也不会报错，就是没有查询结果



-- 事务：把多个相关的操作捆绑成一个逻辑单元，要么全成功，要么全失败
-- 对于事务，开始于第一个操作，结束于：
--    1.要么提交结束，所有的操作都成功
--    2.回滚结束，所有操作都失败，回滚到事务开始之前的状态


-- DML语句，会引起数据库中发生一个事务
-- 第一个执行的DML语句，会引起事务
-- 事务可以以回滚的方式结束，所有的操作被放弃，回滚到开始之前的状态
-- 事务也可以以提交方式结束，对数据库的修改被永久的保存，其他用户可以看到
-- 被修改的数据，在事务没有结束之前，只有当前用户可以看到对数据库的修改操作
-- 其他用户看不到

-- 一次性的插入多条数据，复制表中的数据
INSERT INTO DEPT_BAK SELECT * FROM DEPT;

-- UPDATE
-- 使用UPDATE 语句的时候，在事务没有结束之前，该条数据会被锁住, 其他的用户
-- 无法修改这条数据
-- 事务结束之后，该条数据的锁被放开，其他用户才可以操作这条数据

-- FOR UPDATE也是DML语句，它在执行的时候，会锁住整个表


-- 合并语句 MERGE (Oracle专有，从Oracle9i开始引入)
MERGE INTO DEPT_BACK D
USING DEPT S
ON (D.DEPTNO = S.DETPNO)
WHEN MATCHED THEN
    UPDATE SET D.DNAME = S.DNAME, D.LOC_ID = S.LOC_ID
WHEN NOT MATCHED THEN
    INSERT VALUES (S.DEPTNO, S.DNAME, S.LOC_ID);
