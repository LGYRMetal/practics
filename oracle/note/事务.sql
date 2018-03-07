-- 1. 事务是一组相关的数据改变的逻辑集合。在一个事务中的数据的改变(DML语句
--    引起的)保持着一致的状态，数据的改变同时成功或者同时失败
-- 
-- 2. Oracle数据库的事务由以下语句组成:
--    2.1. 一组DML语句，修改的数据在他们中保持一致
--    2.2. 一个DDL(Data Define Language) 语句
--    2.3. 一个DCL(Data Control Language) 语句
--
-- 3. 事务开始于第一个DML语句
--    事务的结束点:
--          手动结束：
--                   手动提交  COMMIT
--                   手动回滚  ROLLBACK
--          自动结束:
--                   自动提交 DDL, DCL, SQL Plus正常退出
--                   自动回滚 系统崩溃，客户端与服务端连接异常中断，
--                   从SQL Plus中强行退出
--    事务会在多种情况下结束。通常应该有产生事务的用户会话显示的控制事务的
--    结束(COMMIT 和 ROLLBACK),这样可以保证事务中数据改变的可控性。
--    由于隐式结束事务的不可预料性，应该尽量避免隐式的结束事务
--
-- COMMIT 和 ROLLBACK的优点
--  1. Oracle中控制事务的主要命令是 COMMIT 和 ROLLBACK 命令，还有一个辅助
--     的 SAVEPOINT 命令
--  2. 使用COMMIT 和 ROLLBACK 来控制事务的优点有:
--     2.1. 保证数据的一致性，修改过的数据(不一致的数据) 在没有提交之前其他
--          用户是不能看到的
--     2.2. 在数据永久性生效之前重新查看修改的数据
--     2.3. 将相关的操作组织在一起。一个事务中的相关数据改变或者全部成功，
--          或者全部失败

-- 在事务中使用SAVEPOINT, SAVEPOINT只在事务之中有效, 事务结束后，SAVEPOINT
-- 统统失效
INSERT INTO DEPT VALUE (50, '开发', 1114);
SAVEPOINT A;
DELETE FROM DEPT D WHERE D.DEPTNO > 30;
SAVEPOINT B;
UPDATE DEPT D SET D.DNAME = '人事部' WHERE D.DEPTNO = 10;
ROLLBACK TO B; -- 有效
COMMIT;        -- 事务结束
ROLLBACK TO A; -- 无效, 提示从为创建SAVEPOINT A

-- 事务处理的ACID特性
-- Atomic: 原子性
--   事务应作为一个工作单元，事务处理完成，所有的工作要么都在数据库中保存
--   下来， 要么完全回滚，全部不保留
--
-- Consistent: 一致性
--   事务完成或者撤销后，都应该处于一致的状态
--
-- Isolated: 隔离性
--   多个事务同时进行，他们之间应该互不干扰。应该防止一个事务处理其他事务
--   也要修改的数据时，不合理的存取和不完整的读取数据
--
-- Durable: 永久性
--   事务提交后，所做的工作就被永久的保存下来
