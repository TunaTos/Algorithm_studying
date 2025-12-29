/*
    테이블)
    ANIMAL_INS
    
    동물 ID
    이름이 있는 동물
    오름차순 정렬
*/

select
    ANIMAL_ID
from
    ANIMAL_INS
where
    !isnull(name)
order by
    1 asc