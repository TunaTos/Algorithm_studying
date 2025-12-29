/*
    ANIMAL_INS
    
    출력 컬럼)
    생물 종, 이름, 성별 및 중성화 여부
    
    NAME에 NULL -> No name
    
    정렬)
    아이디 asc
*/

select
    ANIMAL_TYPE, 
    ifnull(NAME, 'No name') as NAME, 
    SEX_UPON_INTAKE
from
    ANIMAL_INS
order by
    ANIMAL_ID asc