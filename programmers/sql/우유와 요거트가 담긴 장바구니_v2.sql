/*
2026.04.24
테이블
CART_PRODUCTS

Milk, Yogurt -> 동시에 구입한 장바구니의 ID
정렬) 장바구니 ID


count를 세는 건 안된다
NAME을 distinct를 한다
*/


select
    cart_id
from
    CART_PRODUCTS
where
    NAME in ('Milk', 'Yogurt')
group by
    CART_ID
having 
    count(distinct name) = 2
order by
    1 asc