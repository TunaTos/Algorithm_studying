/*
2026-04-23
테이블)
ANIMAL_INS
ANIMAL_OUTS


보호소 들어올 때는 중성화 x(Intact), 보호소를 나갈 때 o (Spayed, Neutered) 
ID, 생물 종, 이름

substr(1,)
*/

select
    ANIMAL_ID,
    ANIMAL_TYPE,
    NAME
from
    (
        select
            *
        from
            ANIMAL_INS
        where
            substr(SEX_UPON_INTAKE, 1, 6) = 'Intact'
    ) T1
where
    ANIMAL_ID in (
        select
            ANIMAL_ID
        from
            ANIMAL_OUTS
        where
            substr(SEX_UPON_OUTCOME, 1, 6) = 'Spayed'
            or
            substr(SEX_UPON_OUTCOME, 1, 8) = 'Neutered'
    )
