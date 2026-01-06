/*
    Table)
        Employee
        Department
    Employee.departmentId -> Department.id

    highest salary in each of the department
    
    ordering)
        any order
*/

select 
    D.name as Department,
    E.name as Employee,
    E.salary as Salary
from
    Department D
inner join
    Employee E
on
    D.id = E.departmentId
where
    (D.name, E.salary) in 
    (
select
    D.name as Department,
    max(E.salary) as Salary
from
    Employee E
inner join
    Department D
on
    D.id = E.departmentId
group by
    D.name
)