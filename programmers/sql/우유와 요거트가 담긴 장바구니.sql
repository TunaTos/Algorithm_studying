/*
    CART_PRODUCTS
    ID : 테이블의 아이디
    CART_ID : 장바구니 아이디
    
    
    우유(Milk)와 요거트(Yogurt)를 동시에 구입한 
    CART_ID
    
    정렬)
    장바구니 ID asc
*/

select
    distinct(P1.CART_ID) as CART_ID
from
    (
        select
            CART_ID,
            NAME
        from
            CART_PRODUCTS
    ) P1
inner join
    (
        select
            CART_ID,
            NAME
        from   
            CART_PRODUCTS
    ) P2
on
    P1.CART_ID = P2.CART_ID
where
    (P1.NAME = 'Milk' and P2.NAME = 'Yogurt')
    or
    (P1.NAME = 'Yogurt' and P2.NAME = 'Milk')
order by
    1