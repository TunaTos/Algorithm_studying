/*
테이블)
    FOOD_PRODUCT

nullable)
    PRODUCT_CD
    CATEGORY
    PRICE

식품분류(CATEGORY)별 가격(PRICE)이 가장 비싼 식품
필터링 -> '과자', '김치', '식용류'
PRICE -> 내림차순
*/

select
    P1.CATEGORY,
    P1.PRICE as MAX_PRICE,
    P1.PRODUCT_NAME
from
    FOOD_PRODUCT P1
inner join
        (
        select
            CATEGORY,
            max(PRICE) as maxprice
        from
            FOOD_PRODUCT
        where
            CATEGORY in ('과자', '국', '김치', '식용유')
        group by
            CATEGORY
        ) P2
    on
        P1.PRICE = P2.maxprice
        and
        P1.CATEGORY = P2.CATEGORY
order by
    2 desc