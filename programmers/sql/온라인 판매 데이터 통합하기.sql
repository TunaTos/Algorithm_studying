/*
    테이블)
    ONLINE_SALE
    OFFLINE_SALE
    
    조건)
    [ONLINE_SALE]
    동일한 날짜, 회원 ID, 상품 ID조합은 하나의 판매 데이터만 존재한다.
    [OFFLINE_SALE]
    동일한 날짜, 상품 ID
    
    2022년 3월의 오프라인/온라인 상품 판매 데이터
    
    판매 날짜, 상품ID, 유저ID, 판매량
    
    OFFLINE_SALE 판매 데이터의 USER_ID는 NULL
    
    정렬)
    판매일 기준으로 asc
    상품 ID asc
    유저 ID asc
*/

select
    DATE_FORMAT(SALES_DATE, '%Y-%m-%d') as SALES_DATE,
    PRODUCT_ID,
    USER_ID,
    SALES_AMOUNT
from
    (
        select
            SALES_DATE,
            PRODUCT_ID,
            NULL as USER_ID,
            SALES_AMOUNT
        from
            OFFLINE_SALE
        
        UNION ALL
        
        select
            SALES_DATE,
            PRODUCT_ID,
            USER_ID,
            SALES_AMOUNT
        from
            ONLINE_SALE
    ) t
where
    SALES_DATE >= '2022-03-01'
    and
    SALES_DATE < '2022-04-01'
order by
    SALES_DATE asc,
    PRODUCT_ID asc,
    USER_ID asc