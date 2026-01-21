/*
    Table)
        RequestAccepted
*/

select
    t.requester_id as 'id',
    count(*) as 'num'
from(
select
    R1.requester_id,
    R1.accepter_id
from
    RequestAccepted R1
union all
select
    R2.accepter_id,
    R2.requester_id
from
    RequestAccepted R2
) t
group by
    t.requester_id
order by
    2 desc
limit
    1
