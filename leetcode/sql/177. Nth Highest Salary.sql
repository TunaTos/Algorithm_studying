CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    select 
        distinct(r.salary)
    from
        (select
            salary,
            dense_rank() over (order by salary desc) as rk
        from
            Employee
        ) r
    where r.rk = N
  );
END
