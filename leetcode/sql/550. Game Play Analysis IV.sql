/*
    테이블)
        Activity
    
    소수 2의 자리의 수까지 rount(x,2)
*/
select round(
(select
    count(player_id)
from
    Activity
where
    (player_id, event_date) in (
select 
    player_id,
    ADDDATE(min(event_date), 1) as event_date
from
    Activity
group by
    player_id
)) / (
    select
        count(distinct(player_id))
    from
        Activity
    ), 2) as 'fraction'