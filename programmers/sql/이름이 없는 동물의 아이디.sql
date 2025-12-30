/*
    ANIMAL_INS
    
    이름이 없는 채로 들어온 동물
    
    ID
    
    정렬)
        ID -> 오름차순
*/

select
    ANIMAL_ID
from
    ANIMAL_INS
where
    isnull(NAME)
order by
    ANIMAL_ID asc