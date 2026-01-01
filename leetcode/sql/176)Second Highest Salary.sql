select (
    select 
        distinct salary
    from
        Employee
    order by
        salary desc
    limit 1
    offset 1
) as SecondHighestSalary

/*
    스칼라 서브쿼리는 행 값들이 없으면
    null을 출력한다.
*/
