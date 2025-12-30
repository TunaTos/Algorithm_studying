/*
    테이블)
    USER_INFO
    ONLINE_SALE
    
    특이사항)
    GENDER -> 비어있거나, 0(남자) 1(여자)
    동일한 날짜, 회원 ID, 상품 ID 조합에서는 하나의 판매 데이터만 존재한다.
    
    년, 월, 성별로 회원수를 집계해라
    [정렬]
    년
    월
    성별 asc
    
    
    성별 정보가 없으면 필터링
*/

select
    ONLINE_SALE.YEAR,
    ONLINE_SALE.MONTH,
    USER_INFO.GENDER,
    count(distinct USER_INFO.USER_ID) as USERS

from
    (
        select
            USER_ID,
            GENDER
        from
            USER_INFO
        where
            GENDER is not null
    ) USER_INFO
inner join
    (
        select
            MONTH(SALES_DATE) as MONTH,
            YEAR(SALES_DATE) as YEAR,
            USER_ID
        from
            ONLINE_SALE
    ) ONLINE_SALE
on
    USER_INFO.USER_ID = ONLINE_SALE.USER_ID
group by
    YEAR, MONTH, GENDER
order by
    1,
    2,
    3