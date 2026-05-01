/*
테이블)
FIRST_HALF
JULY

같은 맛의 아이스크림이라도, 다른 출하 번호를 가짐

7월의 아이스크림 주문량 + 상반기의 아이스크림 총 주문량
상위 3개

*/

select
    T1.FLAVOR
from
(select
    FLAVOR as FLAVOR,
    sum(TOTAL_ORDER) as TOTAL
from
    FIRST_HALF
group by
    FLAVOR
) T1
inner join
(
select
    FLAVOR as FLAVOR,
    sum(TOTAL_ORDER) as TOTAL
from 
    JULY
group by
    FLAVOR
) T2
on
T1.FLAVOR = T2.FLAVOR
order by
    T1.TOTAL + T2.TOTAL desc
limit
    3