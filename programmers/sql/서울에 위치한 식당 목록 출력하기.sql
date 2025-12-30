/*
    테이블)
    REST_INFO
    REST_REVIEW
    
    서울에 위치한 식당들의
    
    리뷰 평균점수는 소수점 세 번째 자리에서 반올림해라
    [정렬]
    평균 점수로 내림차순
    즐겨찾기 내림차순
*/
select
    REST_INFO.REST_ID,
    REST_INFO.REST_NAME,
    REST_INFO.FOOD_TYPE,
    REST_INFO.FAVORITES,
    REST_INFO.ADDRESS,
    FORMAT(avg(REST_REVIEW.REVIEW_SCORE), 2) as SCORE
from
    (
        select
            *
        from
            REST_INFO
        where
            substr(address,1,2) = '서울'
    ) REST_INFO
inner join
    (
        select
            *
        from
            REST_REVIEW
        
    ) REST_REVIEW
on
    REST_INFO.REST_ID = REST_REVIEW.REST_ID
group by
    REST_ID
order by
    6 desc,
    4 desc