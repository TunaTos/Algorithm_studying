/*
    ANIMAL_INS
    ANIMAL_OUTS
    
    입양을 간 동물 중, 
    보호 기간이 가장 길었던 동물
    2 마리의 아이디와 이름
    
    보호 기간이 긴 순으로 조회
*/
select
    I.ANIMAL_ID, 
    I.NAME
from
    ANIMAL_INS I
inner join
    ANIMAL_OUTS O
on
    I.ANIMAL_ID = O.ANIMAL_ID
order by
    TIMESTAMPDIFF(SECOND, I.DATETIME, O.DATETIME) DESC
limit
    2