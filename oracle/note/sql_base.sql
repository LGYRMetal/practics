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
