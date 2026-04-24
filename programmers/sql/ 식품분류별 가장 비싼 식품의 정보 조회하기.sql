
/*
2026.04.24
테이블)
FOOD_PRODUCT
*/

select
    CATEGORY as 'CATEGORY',
    PRICE as 'MAX_PRICE',
    PRODUCT_NAME as 'PRODUCT_NAME'
from
    FOOD_PRODUCT
where
    (CATEGORY, PRICE) in (
select
    CATEGORY as 'CATEGORY',
    max(price) as 'MAX_PRICE'
from
    FOOD_PRODUCT
where
    CATEGORY in ('과자', '국', '김치', '식용유')
group by
    CATEGORY
)
order by
    MAX_PRICE desc;