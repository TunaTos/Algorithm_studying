/*
    PLACES
    
    ID, NAME, HOST_ID
    
    공간을 둘 이상 등록한 사람 -> "헤비 유저"
    ID, NAME, HOST_ID
    아이디 순서대로 정렬
*/
select
    ID, NAME, HOST_ID
from
    PLACES
where
    HOST_ID 
in (
    select
        HOST_ID
    from
        PLACES
    group by
        HOST_ID
    having
        COUNT(HOST_ID) > 1
)
order by
    ID asc