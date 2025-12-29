/*
    테이블)
    FISH_INFO
    
    잡은 물고기가 10cm 이하인 경우 -> NULL
    
    평균 길이가 33cm 이상인 물고기들을 종류별로
    잡은 수, 최대 길이, 물고기 종류
    10cm 이하는 10cm로 해라
    
    정렬)
    물고기 종류 asc
*/


select
    count(*) as FISH_COUNT,
    max(LENGTH) as MAX_LENGTH,
    FISH_TYPE
from
    (
        select
            ID,
            FISH_TYPE,
            IFNULL(LENGTH, 10) as LENGTH
        from
            FISH_INFO
    ) F
group by
    FISH_TYPE
having
    avg(LENGTH) >= 33
order by
    FISH_TYPE asc