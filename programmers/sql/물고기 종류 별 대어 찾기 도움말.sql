/*
테이블)
FISH_INFO
FISH_NAME_INFO


조건)
if length <= 10cm -> NULL

종류 별로 가장 큰 물고기의
ID, 이름, 길이
정렬)
물고기 ID asc

10cm 이하의 물고기가 가장 큰 경우는 없다
*/
select
    DM.ID as ID,
    NI.FISH_NAME as FISH_NAME,
    DM.LENGTH LENGTH
from
    FISH_NAME_INFO NI
inner join 
(select
    *
from
    FISH_INFO I
where
    (I.FISH_TYPE, I.LENGTH) in (
select
    FISH_TYPE,
    max(LENGTH)
from
    FISH_INFO
group by
    FISH_TYPE
)) DM
on DM.FISH_TYPE = NI.FISH_TYPE
order by
    1