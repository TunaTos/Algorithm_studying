/*
2026.04.28)

ECOLI_DATA

3세대의 대장균
오름차순

일단 2세대의 PARENT_ID를 구한다
2세대의 ID를 PARENT로 가지고 있는 걸 구한다
*/

select
    ID
from
    ECOLI_DATA
where
    PARENT_ID in (
select
    ID
from
    ECOLI_DATA
where
    PARENT_ID in (select ID from ECOLI_DATA where PARENT_ID is null))
order by
    ID asc