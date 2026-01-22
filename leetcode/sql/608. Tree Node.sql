/*
    p_id가 null이다 -> "Root"
    p_id가 null이 아니다
        자식count가 0이다 -> "Leaf"
        자식count가 >=0이다 -> "Inner"
*/
select
    t1.id,
    (case
        when t1.p_id is null then 'Root'
        when t1.p_id is not null and c_cnt = 0 then 'Leaf'
        else 'Inner'
        end) as 'Type'
from
    (select
        T1.id as 'id',
        T1.p_id as 'p_id',
        sum(case 
                when T2.id is null then 0 
                else 1 
                end) as c_cnt
    from
        Tree T1
    left join
        Tree T2
    on
        T1.id = T2.p_id
    group by
        T1.id) t1


# count(특정 컬럼) -> null을 포함하지 않는다
# count(*) -> null을 포함한다
