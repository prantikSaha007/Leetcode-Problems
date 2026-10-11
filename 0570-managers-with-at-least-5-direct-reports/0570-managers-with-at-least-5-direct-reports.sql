# Write your MySQL query statement below
-- SELECT e1.name FROM Employee e1
-- JOIN (
--     SELECT managerId,COUNT(*) AS directReports
--     FROM Employee
--     GROUP BY managerId
--     HAVING COUNT(*)>=5
-- ) e2 ON e1.id=e2.managerId;
 
 SELECT e.name FROM Employee e
    JOIN Employee m ON e.id=m.managerId
    GROUP BY m.managerID
    HAVING COUNT(m.managerId)>=5;
