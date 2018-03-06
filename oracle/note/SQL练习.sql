select *
from emp;

select *
from users;

select *
from emp
for update;

alter session set language="en_US.utf-8";

alter session set nls_language="AMERICAN";

INSERT INTO EMP VALUES
(7788,'SCOTT','ANALYST',7566,to_date('13-JUL-87')-85,3000,NULL,20);

INSERT INTO EMP VALUES
(7876,'ADAMS','CLERK',7788,to_date('13-JUL-87')-51,1100,NULL,20);

INSERT INTO EMP VALUES
(7877,'LGY','CLERK',7788,to_date('13-3月-2018'),2000,NULL,20);





-- 1. 选择部门30中的雇员
SELECT *
FROM EMP
WHERE DEPTNO = 30;

-- 2. 列出所有办事员的姓名、编号和部门
SELECT EMPNO 员工编号, ENAME 姓名, JOB 岗位, DEPTNO 部门编号
FROM EMP
WHERE JOB = 'CLERK';

-- 3. 找出佣金高于薪金的雇员
SELECT *
FROM EMP
WHERE COMM > SAL;

-- 4. 找出佣金高于薪金60%的雇员
SELECT *
FROM EMP
--WHERE SAL * 0.6 = COMM - SAL;
WHERE COMM > SAL * 0.6

-- 5. 找出部门10中所有经理和部门20中的所有办事员的详细资料
SELECT *
FROM EMP
WHERE (DEPTNO = 10 AND JOB = 'MANAGER') OR (DEPTNO = 20 AND JOB = 'CLERK');

-- 6. 找出部门10中所有经理、部门20中所有办事员，既不是经理又不是办事员但其
--    薪金 >=2000的所有雇员的详细资料
SELECT *
FROM EMP
WHERE (DEPTNO = 10 AND JOB = 'MANAGER') OR
      (DEPTNO = 20 AND JOB = 'CLERK') OR
      (JOB != 'MANAGER' AND JOB != 'CLERK' AND SAL >= 2000);

-- 7. 找出收取佣金的雇员的不同工作
SELECT DISTINCT JOB
FROM EMP
WHERE COMM IS NOT NULL;

-- 8. 找出不收取佣金或收取的佣金低于100的雇员
SELECT *
FROM EMP
WHERE COMM IS NULL OR COMM < 100;

-- 9. 找出早于12年之前受雇的雇员
SELECT *
FROM EMP
WHERE (SYSDATE - HIREDATE) / 365 > 12;

-- 10. 显示只有首字母大写的所有雇员的姓名
-- SELECT SUBSTR(ENAME, 1, 1) || LOWER(SUBSTR(ENAME, 2)) 姓名
SELECT INITCAP(ENAME) "姓名"
FROM EMP;

-- 11. 显示正好为15个字符的雇员姓名
SELECT ENAME 姓名
FROM EMP
WHERE LENGTH(ENAME) = 15;

-- 12. 显示不带有'R'的雇员姓名
SELECT ENAME 姓名
FROM EMP
WHERE ENAME NOT LIKE '%R%';

-- 13. 显示所有雇员的姓名的前三个字符
SELECT SUBSTR(ENAME, 0, 3) 姓名
FROM EMP;

-- 14. 显示所有雇员的姓名，用a替换所有'A'
SELECT REPLACE(ENAME, 'A', 'a') 姓名
FROM EMP;

-- 15. 显示所有雇员的姓名以及满10年服务年限的日期
SELECT ENAME 姓名, HIREDATE + 365 * 10 满10年服务年限的日期
FROM EMP;

-- 16. 显示雇员的详细资料，按姓名排序
SELECT *
FROM EMP
ORDER BY ENAME;

-- 17. 显示雇员姓名，根据其服务年限，将最老的雇员排在最前面
SELECT ENAME 姓名, (SYSDATE - HIREDATE) / 365 服务年限
FROM EMP
ORDER BY 服务年限 DESC;

-- 18. 显示所有雇员的姓名、工作和薪金，按工作内的工作的降序顺序排序，而工作
--     按薪金排序
SELECT ENAME 姓名, JOB 工作, SAL 薪金
FROM EMP
ORDER BY 工作 DESC, 薪金 ASC;

-- 19. 显示所有雇员的姓名和加入公司的年份和月份，按雇员受雇日所在月排序，将
--     最早年份的项目排在最前面
SELECT ENAME "姓名",
       EXTRACT(year FROM HIREDATE) "加入公司年份",
       EXTRACT(month FROM HIREDATE) "加入公司月份"
FROM EMP
ORDER BY "加入公司年份" ASC, "加入公司月份" ASC;

-- 20. 显示在一个月为30天的情况下所有雇员的日薪金
SELECT EMPNO 员工编号,
       ENAME 姓名,
       JOB 职位,
       SAL 月薪,
       SAL / 30 日薪,
       DEPTNO 部门
FROM EMP;

-- 21. 找出在(任何年份的)2月受聘的所有雇员
SELECT *
FROM EMP
WHERE EXTRACT(month FROM HIREDATE) = 2;

-- 22. 对于每个雇员，显示其加入公司的天数
SELECT ENAME 姓名, SYSDATE - HIREDATE 加入公司天数
FROM EMP;

-- 23. 显示姓名字段的任何位置，包含"A"的所有雇员的姓名
SELECT ENAME
FROM EMP
WHERE ENAME LIKE '%A%';
