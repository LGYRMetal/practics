-- 数据库对象
-- ------------------------------------------------------------
-- | 对象名称 |                     描述                      |
-- ------------------------------------------------------------
-- | 表       | 基本的数据存储对象，以行和列的形式存在        |
-- ------------------------------------------------------------
-- | 约束     | 执行数据校验，保证数据完整性的对象            |
-- ------------------------------------------------------------
-- | 视图     | 一个或多个表数据的显示                        |
-- ------------------------------------------------------------
-- | 索引     | 用于提高查询的速度                            |
-- ------------------------------------------------------------
-- | 同义词   | 对象的别名                                    |
-- ------------------------------------------------------------

-- 建表语句
CREATE TABLE STUDENT(
    SID NUMBER(4) PRIMARY KEY,
    SNAME VARCHAR2(10),
    GRADE VARCHAR2(20),
    SEX CHAR(2) DEFAULT '男',
    BIRTHDAT DATE
);

-- 在不影响数据的情况下，对表做出修改，对标的修改，主要是对字段的修改
-- 主要的操作：
--  1. 添加字段
ALTER TABLE STUDENT
ADD TEL VARCHAR2(11);
-- 添加字段总是可以成功，新添加的字段出现在表的最后面

--  2. 修改字段(修改字段类型，修改字段长度)
--     在该字段没有数据的时候，字段的类型和字段的长度都是可以修改的
ALTER TABLE STUDENT
MODIFY TEL NUMBER(11);
--     对于缺省值的修改，不会影响已经存在的数据，只会对以后插入的数据产
--     生影响
ALTER TABLE STUDENT
MODIFY SEX CHAR(2) DEFAULT '女';
--     当该字段有数据的时候，字段的类型是不能修改的，字段的长度是可以修改
--     的，增大总是可以的，减少要看数据的实际长度
ALTER TABLE STUDENT
MODIFY GRADE VARCHAR2(30); -- 增大

ALTER TABLE STUDENT
MODIFY GRADE VARCHAR2(10); -- 减少,需要看数据的实际长度，如果小于数据的实际
                           -- 长度，则报错，修改数据类型会报错
--  3. 删除字段
ALTER TABLE STUDENT
DROP COLUMN ADDR;
-- 有数据也照删不误


-- 在创建报的时候使用子查询
CREATE TABLE DEPT_BACK
AS
SELECT * FROM DEPT;

-- 删除表
-- 表中所有的数据将被删除
-- 没有完成的事务被提交
-- 所有相关的索引被删除
-- 不能回滚
DROP TABLE DEPT_BACK;

-- 只用DEPT的部分字段建立新表, 而且可以给字段使用别名
CREATE TABLE DEPT_BACK
AS
SELECT DEPTNO "部门编号", DNAME "部门名称" FROM DEPT WHERE DEPTNO <= 30;

CREATE TABLE DEPT_BACK
(部门编号， 部门名称, 位置编号) -- 字段必须和DEPT的字段数量一致
AS
SELECT * FROM DEPT;


-- TRUNCATE TABLE
-- 删除表的数据, TRUNCATE TABLE 比DELETE的删除速度快，但该命令一定要谨慎使用
-- 因为DELETE可以回滚，而TRUNCATE TABLE是DDL语句，不支持回滚
-- 释放表的存储空间，DELETE命令不释放空间
TRUNCATE TABLE DEPT_BACK;


-- 改变对象的名称, 使用Oracle的RENAME命令
-- 可以修改表、视图、序列、同义词的名称
-- 必须是对象的所有者，即使是DBA也不行
-- 语法:
--       RENAME old_name TO new_name;
RENAME STUDENT TO STUDENTS;



--------------------------- 约束 ------------------------------------
-- 1. 约束是在表上强制执行的数据校验规则，被插入，修改或删除的数据必须符合
--    相关字段上设置的的这些检验条件，也就是约束条件
-- 2. 约束条件可以是构建在一个表的单个字段上，也可以是构建在一个表的多个
--    字段上。
-- 3. 当表中的数据有相互依赖性时，可以保护相关的的数据不被删除
-- 4. Oracle支持下面五类完整性约束：
--    NOT NULL 非空
--    UNIQUE KEY 唯一键
--    PRIMARY KEY 主键
--    FOREIGN KEY 外键
--    CHECK 检察
-- 
-- 约束必须要建立在表上，但是约束是一个独立的数据库对象，
-- 简单的说，没有表，也就没有约束
-- 创建约束的操作，可以在建表的时候同时创建约束，也可以在表建好以后，通过
-- ALTER TABLE 来给表添加约束
-- 约束也是一个独立的数据库对象，也需要命名，有两种方式
--  1. 手动给约束命名
--  2. Oracle给约束自动命名

-- 非空约束，唯一一个可以定义在列级的约束（只能看守一个字段）,确保该字段
-- 不能为NULL
-- 除了主键约束之外，一个表中可以同时存在多种相同类型的约束
CREATE TABLE STUDENTS(
    SID NUMBER(4) PRIMARY KEY,
    SNAME VARCHAR2(20) CONSTRAINT SNAME_NN NOT NULL -- 手动命名的非空约束
    GRADE VARCHAR2(20) NOT NULL -- 系统自动命名的非空约束
);

-- 唯一约束，保证该字段的数据不能重复，或字段组合不能重复，但可以为null
-- 唯一约束可以作用在单个字段上(称为列级约束)
CREATE TABLE STUDENT(
    SID NUMBER(4) PRIMARY KEY,
    SNAME VARCHAR2(20) NOT NULL,
    EMAIL VARCHAR2(20),
    CONSTRAINTS EMAIL_UNI UNIQUE(EMAIL)
);
-- 下面两条不算重复，不违反唯一性约束
INSERT INTO STUDENT VALUES(1, 'a', NULL);
INSERT INTO STUDENT VALUES(2, 'b', NULL);

-- 唯一约束也可以同时作用在多个字段上(称为表级约束)
CREATE TABLE STUDENT(
    SID NUMBER(4) PRIMARY KEY,
    FIRST_NAME VARCHAR2(10),
    LAST_NAME VARCHAR2(20),
    CONSTRAINTS NAME_UNI UNIQUE(FIRST_NAME, LAST_NAME)
);
-- 下面两个算重复，违反唯一性约束
INSERT INTO STUDENT VALUES(1000, '张', NULL);
INSERT INTO STUDENT VALUES(1001, '张', NULL);
-- 下面两个不算重复，不违反唯一性约束
INSERT INTO STUDENT VALUES(1000, NULL, NULL);
INSERT INTO STUDENT VALUES(1001, NULL, NULL);
-- 唯一约束在一个表中也可以同时存在多个


-- 主键约束
-- 从功能上说，相当于 非空且唯一
-- 通过主键可以唯一确定一条记录
-- 在一个表中只能有一个主键约束
-- 选择主键的原则:
-- 在选择主键的时候，不要使用尸体的业务数据来当作主键，因为业务数据是可以
-- 变化的。应该用一个和实体无关的流水号来当作表的主键
-- 
-- 主键约束作用在单个字段上
CREATE TABLE STUDENT(
    SID NUMBER(4),
    SNAME VARCHAR2(20),
    CONSTRAINTS PK_STU PRIMARY KEY (SID)
);

-- 主键约束同时作用在多个字段上,联合主键,其中的任何一个字段为空都不行
CREATE TABLE STUDENT(
    FIRST_NAME VARCHAR2(10),
    LAST_NAME VARCHAR2(20),
    GRADE VARCHAR2(20),
    CONSTRAINTS PK_STU PRIMARY KEY (FIRST_NAME, LAST_NAME)
);



-- 外键约束
-- 可以重复，可以为空
-- 外键约束关系到两个表的两个字段之间的关系
-- 在外键约束下，在建表的时候要先建立父表，后建立子表
-- 在外键约束下，再添加数据的时候，要先添加父表数据，后添加子表数据
--               在删除数据的时候，要先删除子表数据，后删除父表数据
--               在删除表的时候，要先删除子表，后删除父表

-- 一对多（多对一)关系的主外键的实现
-- 子表
CREATE TABLE EMP(
    EMPNO NUMBER(4) PRIMARY KEY,
    ENAME VARCHAR2(10),
    JOB VARCHAR2(10),
    DEPT_NO NUMBER(4),
    -- 外键约束建立在多的一方（一对多的关系）
    CONSTRAINTS FK_EMP FOREIGN KEY (DEPT_NO) REFERENCES DEPT (DEPTNO)
);

-- 父表
CREATE TABLE DEPT(
    DEPTNO NUMBER(4) PRIMARY KEY,
    DNAME VARCHAR2(10),
);

-- 选择外键原则:
-- 父表中的 主键字段 或 唯一键字段 可以被子表因为外键

-- 在建立好表之后，通过 ALTER TABLE 给表添加外键约束
ALTER TABLE EMP
ADD CONSTRAINTS FK_EMPL FOREIGN KEY (DEPT_NO) REFERENCES DEPT (DEPTNO);


-- 一对一关系的主外键实现
-- 在外键上同时设置唯一约束
CREATE TABLE CARD(
    CID NUMBER(4) PRIMARY KEY,
    CNAME VARCHAR2(10)
);

CREATE TABLE PERSON(
    PID NUMBER(4) PRIMARY KEY,
    PNAME VARCHAR2(20),
    CID NUMBER(4),
    CONSTRAINTS FK_PER_CARD FOREIGN KEY (CID) REFRENCES CARD (CID),
    CONSTRAINT CID_UNI UNIQUE (CID) -- CONSTRAINT 单数形式
);



-- 多对多关系的实现
-- 需要创建一个关系表，把两个表的主键都引导关系表中
CREATE TABLE STUDENT(
    SID NUMBER(4) PRIMARY KEY,
    SNAME VARCHAR2(20),
);

CREATE TABLE COURSE(
    CID NUMBER(4) PRIMARY KEY,
    CNAME VARCHAR2(20),
);

-- 两种方式
-- 1. 关系表中可以用上面两个表的主键既当作外键，同时又把外键当作联合主键
CREATE TABLE STU_COUR(
    SID NUMBER(4),
    CID NUMBER(4),
    CONSTRAINT FK1 FOREIGN KEY (SID) REFRENCES STUDENT (SID),
    CONSTRAINT FK2 FOREIGN KEY (CID) REFRENCES COURSE (CID),
    CONSTRAINT PK_STU_COUR PRIMARY KEY (SID, CID)
);

-- 2. 关系表中可以用上面两个表的主键当作外键，关系包有自己独立的主键
CREATE TABLE STU_COUR(
    SCID NUMBER(4) PRIMARY KEY,
    SID NUMBER(4),
    CID NUMBER(4),
    CONSTRAINT FK1 FOREIGN KEY (SID) REFERENCES STUDENT (SID),
    CONSTRAINT FK2 FOREIGN KEY (CID) REFERENCES STUDENT (CID)
);


-- 索引
-- 创建索引有两种方式
-- 1. 自动创建：Oracle会自动为主键和唯一键创建索引,而且会随主键或唯一键的
--    变化自动跟着改变
-- 给ENAME字段创建唯一性约束，会自动为ENAME字段创建索引ENAME_UNI
ALTER TABLE EMP
ADD CONSTRAINTS ENAME_UNI UNIQUE (ENAME);

-- 删除ENAME上的唯一性约束，会自动删除ENAME字段上的索引ENAME_UNI
-- 但自动创建的索引是无法手动删除的
ALTER TABLE EMP
DROP CONSTRAINTS ENAME_UNI;


-- 2. 手动创建索引
--    在查询时，经常被用来作为查询条件的字段，应该添加索引
CREATE INDEX ENAME_INDEX ON EMP (ENAME);

-- 删除索引
DROP INDEX ENAME_INDEX;





-- 视图
-- 视图就是一个虚表(下面的“子查询”其实就是一个视图)，
-- 可以从这个表中查询数据
-- 视图就是一个命名的查询语句
-- 任何有效的查询语句，无论多么复制，都可以被创建成一个视图
/*
SELECT *
FROM EMP OR (子查询);
*/

-- 视图的好处
-- 1. 可以限制对数据的访问，让用户通过视图可以看到表中的一部分数据
-- 2. 可以使复杂的查询变得简单
-- 3. 提供了数据的独立性， 用户不用知道数据来源于何处
-- 4. 提供了对相同数据的不同显示

-- 创建视图
-- 给人事经理使用的视图
CREATE VIEW HR_VIEW
AS
SELECT * FROM EMP;

-- 给项目经理使用的视图
CREATE VIEW MGR_VIEW
AS
SELECT EMPNO, ENAME, JOB, HIREDATE, DEPTNO
FROM EMP;

-- 修改/重置视图
CREATE OR REPLACE VIEW MGR_VIEW
AS
SELECT EMPNO, ENAME, JOB, HIREDATE, DEPTNO, COMM
FROM EMP;

-- 删除视图,不会影响原来的数据
DROP VIEW HR_VIEW;

-- 创建视图时，为每个字段指定字段名称
CREATE OR REPLACE VIEW VIEW_EMP
-- CREATE VIEW 语句总的字段与子查询中的字段必须匹配
( 员工编号, 员工姓名, 薪水, 佣金 )
AS
SELECT EMPNO, ENAME, SAL, COMM FROM EMP;


-- 创建视图时，在使用函数的查询字段必须指定别名，否则报错
CREATE OR REPLACE VIEW V_EMP_SAL
AS
SELECT DEPTNO,
       MAX(SAL) MAXSAL, -- 必须指定别名
       MIN(SAL) MINSAL, -- 必须指定别名
       SUM(SAL) SUMSAL, -- 必须指定别名
       AVG(SAL) AVGSAL  -- 必须指定别名
FROM EMP
WHERE DEPTNO IS NOT NULL
GROUP BY DEPTNO
GROUP BY DEPTNO;

-- 视图就是一个(虚)表,我们可以对表插入数据，也可以对视图插入数据
CREATE OR REPLACE V_EMPINFO
AS
SELECT * FROM EMP WHERE SAL > 2000;

-- 对视图插入数据,数据会被插入到原表,但视图主要的功能是查询，所以最好创建
-- 只读的视图，禁止对试图执行DML操作
INSERT INTO V_EMPINFO
VALUES(8000, '张1', '工程师', '7902', '12-8月-1987', 1900, 500, 20);

-- 创建只读视图, 不能执行DML操作
CREATE OR REPLACE VIEW V_EMPINFO
AS
SELECT * FROM EMP WHERE SAL > 2000
WITH READ ONLY;


-- 行内视图，就是出现在FROM后面的子查询，也就是一个视图，但是该试图没有命名
-- 不会在数据库中保存，例:
-- 查询工资最高的前三个人的全部信息
-- 这种放是称为 TOP-N 分析法
SELECT *
FROM (SELECT * FROM EMP ORDER BY SAL DESC)
WHERE ROWNUM <= 3; -- ROWNUM只适用于 < 或 <= 的情况，不能用于 > 或 >= 的情况


------------------------- TOP-N 分析法 -----------------------
-- 数据插入的顺序决定了查询数据是的顺序，也就决定了 ROWNUM 的顺序

-- 1. rownum 对于等于某值的查询条件
--    如果希望找到学生表中第一条学生的信息，可以使用 ROWNUM = 1 作为条件，
--    但想找到学生表中第二条学生信息，使用 ROWNUM = 2 结果查不到数，因为
--    rownum都是从 1 开始，但是 1 以上的自然数在 ROWNUM 做等于判断时认为
--    都是 false 条件，所以无法查到 ROWNUM = n (n > 1)
--
-- 2. rownum 对于大于某值的查询条件
--    如果想找到从第二行记录以后的记录，当使用 ROWNUM > 2 是查询不出记录的，
--    原因是由于 ROWNUM 是一个总是从 1 开始的伪列，Oracle 认为
--    ROWNUM > n (n > 1) 这种条件依旧不成立，所以查不到记录
--
-- 如果想查到第二行以后的记录，可以使用一下子查询方法来解决 。注意子查询中
-- 的 ROWNUM 必须要有别名，否则还是不会查出记录来，这是因为 ROWNUM 不是某个
-- 表的列，如果不起别名的话，无法知道 ROWNUM 是子查询的列还是主查询的列
SELECT *
FROM (SELECT ROWNUM RN, ID, NAME FROM STUDENT)
WHERE RN <= 4 AND RN >= 2;
--
-- 3. ROWNUM 对于小于某值的查询条件
--    如果想查到第三条记录以前的记录，当使用 ROWNUM < 3 是能够得到两条记录
--    的。显然 ROWNUM 对于 ROWNUM < n (n > 1) 的条件认为是成立的，所以可以
--    找到记录
--
-- 4. 可能有时候需要查询ROWNUM在某区间的数据，那怎么查？从上面的分析中可以
--    看出 ROWNUM 对于小于某值的查询条件是认为true的，ROWNUM 对于大于某值
--    的查询条件直接认为是false的，但是可以使用子查询间接让想要查询的数据
--    转换为true的情况。例如要查询 ROWNUM 在第二行到第三行之间的数据，包括
--    第二行和第三行数据，那么我们只能写一下语句，先让它返回小于等于三的
--    记录行，然后在主查询中判断新的ROWNUM的别名列大于等于二的记录行。但是
--    这样的操作会在大数据集中影响速度
--
-- 5. ROWNUM 和 排序
--    Oracle中的 ROWNUM 是在取数据的时候差生的序号，所以想对指定排序的数据
--    取指定的 ROWNUM 行数据就必须注意了
-- 
-- 可以看出，ROWNUM 并不是按照 name 列来生成的序号，相同是按照记录插入是的
-- 顺序给记录排的号，ROWID 也是顺序分配的，为了解决这个问题，必须使用子查询
-- ROWID 代表数据存放在硬盘中的物理位置地址，可以使用 ROWID 来获得数据的
-- 修改权限


--------------------------- 同义词 ---------------------------------
-- 同义词，就是数据库对象的一个别名，可以简化访问其他用户的数据库对象
SELECT SYSDATE FROM SYS.DUAL;

-- 语法
CREATE OR REPLACE SYNONYM MYDUAL
FOR SYS.DUAL;

SELECT SYSDATE FROM MYDUAL;

-- 删除同义词
DROP SYNONYM MYDUAL;


-------------------------------- 序列 -----------------------
-- 序列，用来维护数据库的主键数据,Oracle特有，相当于MySQL的 自增字段
CREATE TABLE STUDENT(
    SID NUMBER(4) PRIMARY KEY,
    SNAME VARCHAR2(10)
);
-- 创建序列
CREATE SEQUENCE SEQ_STU
MINVALUE 1
MAXVALUE 9999
START WHIT 1
INCREMENT BY 1;
-- 使用序列
INSERT INTO STUDENT VALUES (SEQ_STU.NEXTVAL, '张1');
-- 序列保存在 SYS.DUAL 中
SELECT SEQ_STU.CURRVAL
FROM SYS.DUAL;
