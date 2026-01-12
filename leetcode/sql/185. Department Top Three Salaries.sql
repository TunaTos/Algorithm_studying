SELECT
    D.name   AS Department,
    E.name   AS Employee,
    E.salary AS Salary
FROM Employee E
JOIN Department D
  ON E.departmentId = D.id
WHERE (E.salary, E.departmentId) IN (
    SELECT salary, departmentId
    FROM (
        SELECT
            salary,
            departmentId,
            DENSE_RANK() OVER (
                PARTITION BY departmentId
                ORDER BY salary DESC
            ) AS salary_rank
        FROM Employee
    ) t
    WHERE salary_rank <= 3
);
