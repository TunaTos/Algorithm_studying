/*
    테이블)
    FOOD_FACTORY
    
    강원도에 위치한
    
    정렬)
    공장ID -> 오름차순
*/

select
    FACTORY_ID, FACTORY_NAME, ADDRESS
from
    FOOD_FACTORY
where
    substr(ADDRESS, 1,3) = '강원도' 
order by
    FACTORY_ID