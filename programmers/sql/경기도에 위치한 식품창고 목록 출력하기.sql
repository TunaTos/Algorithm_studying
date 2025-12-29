/*
    테이블)
    FOOD_WAREHOUSE
    
    출력)
    창고의 ID, 이름, 주소, 냉동시설 여부
    냉동시설 -> NULL `N`
    
    정렬)
    창고 ID로 오름차순
*/

select
    WAREHOUSE_ID, 
    WAREHOUSE_NAME, 
    ADDRESS, 
    IFNULL(FREEZER_YN, "N") as FREEZER_YN
from
    FOOD_WAREHOUSE
where
    substring(ADDRESS, 1, 3) = "경기도"
order by
    WAREHOUSE_ID asc
    
