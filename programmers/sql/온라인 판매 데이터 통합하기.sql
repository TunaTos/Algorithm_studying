/*
테이블)
ONLINE_SALE
OFFLINE_SALE

2022년 3월의 온,오프라인 사품
OFFLINE_SALE -> USER_ID = NULL
정렬
    판매일을
    상품 ID
    유저 ID
*/


select
    SALES_DATE,
    PRODUCT_ID,
    USER_ID,
    SALES_AMOUNT
from
    ONLINE_SALE
where
    SALES_DATE >= '2022-03-01' and SALES_DATE < '2022-04-01'
union
select
    SALES_DATE,
    PRODUCT_ID,
    NULL as USER_ID,
    SALES_AMOUNT
from
    OFFLINE_SALE
where
    SALES_DATE >= '2022-03-01' and SALES_DATE < '2022-04-01'
order by
    1 asc,
    2 asc,
    3 asc
