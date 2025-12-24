/*
    부모 개체, 자식 개체
    
    테이블) ECOLI_DATA
    ID : 대장균 개체
    PARENT_ID : 부모 개체의 ID
    SIZE_OF_COLONY : 개체의 크기
    DIFFERENTIATION_DATE : 분화되어 나온 날짜
    GENOTYPE : 개체의 형질
    
    최초의 대장균은 PARENT_ID = NULL
    
    대장균 개체의 ID와 자식의 수를 출력하라
    자식이 없으면 자식의 수는 0으로 출력하라
    
    ID
    오름차순
    
*/

select
    P.ID, COUNT(S.ID) as CHILD_COUNT
from
    (
        select
            ID
        from
            ECOLI_DATA
    )  P
left join
    (
        select
            ID, PARENT_ID
        from
            ECOLI_DATA
    ) S
on
    S.PARENT_ID = P.ID
group by
    P.ID