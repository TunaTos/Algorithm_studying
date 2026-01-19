/*
    Table)
        Employee
    
    managerId == NULL
        employee does not have a manager
    write a manager that direct at least five reports
*/

select
    E1.name
from
    Employee E1
inner join
    Employee E2
where
    E1.id = E2.managerId
group by
    E1.id
having
    count(*) >= 5