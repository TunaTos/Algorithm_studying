/*
    FOOD_ORDER 테이블
    
    2022년 5월 1일 기준으로 
    주문 ID, 제품 ID, 출고일자, 출고여부를 조회하는 SQL
    
    출고여부
        2022.5.1 -> 출고완료
        이후 날짜 -> 출고대기
        미정(NULL) -> 출고미정
    
    주문ID asc
*/


SELECT
    ORDER_ID,
    PRODUCT_ID,
    DATE_FORMAT(OUT_DATE, '%Y-%m-%d') AS OUT_DATE,
    CASE
        WHEN OUT_DATE <= '2022-05-01' THEN '출고완료'
        WHEN OUT_DATE > '2022-05-01' THEN '출고대기'
        WHEN OUT_DATE IS NULL THEN '출고미정'
    END AS OUT_STATUS
FROM
    FOOD_ORDER
ORDER BY
    ORDER_ID ASC;
