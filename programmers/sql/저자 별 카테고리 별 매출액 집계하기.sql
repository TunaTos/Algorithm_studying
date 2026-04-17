/*
테이블)
BOOK
AUTHOR
BOOK_SALES

2022년 1월 DATE
저자, 카테고리 별 (판매량 * 팬매가)
AUTHOR_ID, AUTHOR_NAME, CATEGORY, SALES
정렬)
AUTHOR_ID asc, CATEGORY desc
*/
select
    A.author_id as AUTHOR_ID,
    A.author_name as AUTHOR_NAME,
    O.category as CATEGORY,
    sum(O.price * O.SALES) as TOTAL_SALES
from
    AUTHOR A
inner join
(select
    B.book_id,
    B.category,
    B.author_id,
    B.price,
    S.SALES
from
    BOOK B
inner join
    (select 
        *
     from BOOK_SALES 
     where 
        SALES_DATE >= '2022.01.01'
        and
        SALES_DATE < '2022.02.01'
    ) S
on
    B.BOOK_ID = S.BOOK_ID) O
on
    A.author_id = O.author_id
group by
    A.AUTHOR_NAME, O.category
order by
    A.author_id asc,
    O.category desc