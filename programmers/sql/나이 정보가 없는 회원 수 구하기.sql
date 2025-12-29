/*
    USER_INFO
    
    GENDER -> null or 0 or 1
    
    
    나이 정보가 없는 회원의 count
*/

select
    count(*) as USERS
from
    USER_INFO
where
    isnull(age)
