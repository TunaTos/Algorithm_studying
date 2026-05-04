/*
테이블)
    USER_INFO
    ONLINE_SALE

Gender -> NULL, 0(man), 1(woman) [없는 경우는 결과에서 제외]
정렬)
    년
    월
    성별
*/

select
    S.YEAR as YEAR,
    S.MONTH as MONTH,
    U.GENDER as GENDER,
    count(distinct S.USER_ID) as "USERS"
from
    (
        select
            USER_ID as USER_ID,
            GENDER as GENDER
        from
            USER_INFO
        where
            GENDER is not NULL
    ) U
inner join
    (
        select
            USER_ID as USER_ID,
            YEAR(SALES_DATE) as 'YEAR',
            MONTH(SALES_DATE) as 'MONTH'
        from
            ONLINE_SALE
    ) S
on
    U.USER_ID = S.USER_ID
group by
    S.YEAR, 
    S.MONTH,
    U.GENDER
order by
    1 asc,
    2 asc,
    3 asc