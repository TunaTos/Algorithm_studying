/*
    BOOK_ID, PUBLISHED_DATE 를 출력하라
    Book 테이블에서
    조건 -> 2021년에 출간된 '인문' 카테고리
    정렬 -> 출판일 오름차순
*/

select 
    BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, "%Y-%m-%d") as PUBLISHED_DATE
from
    BOOK
where
    year(PUBLISHED_DATE) = '2021'
    and
    CATEGORY = '인문'
order by
    PUBLISHED_DATE
    asc;