/*
테이블)
FIRST_HALF -> 상반기
JULY -> 7월의 테이블 정보

외래키)
SHIPMENT_ID

7월 아이스크림 총 주문량 + 상반기 총 주문량
큰 순서대로
상위 3개
*/

select
    F.FLAVOR
from
    FIRST_HALF F
inner join
    (
        select
            SHIPMENT_ID,
            FLAVOR,
            sum(TOTAL_ORDER) as SUM
        from
            JULY
        group by
            FLAVOR
    ) J
on
    F.SHIPMENT_ID = J.SHIPMENT_ID
order by
    J.SUM + F.TOTAL_ORDER desc
limit
    3