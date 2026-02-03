/*
    Table)
        Queue
    
    person_id -> 사람 ID
    turn -> 몇 번째로 탔는지 알려줌

    1000 킬로그램의 리미트가 있음
    마지막으로 탈 수 있는 경우

    250 + 350 + 400
*/
select 
    person_name
from
    Queue Q 
where 
    Q.turn = (
    select
        Q1.turn
    from
        Queue Q1
    inner join 
        Queue Q2
    on
        Q1.turn >= Q2.turn
    group by
        Q1.turn
    having
        sum(Q2.weight) <= 1000
    order by
        Q1.turn desc
    limit 1
)