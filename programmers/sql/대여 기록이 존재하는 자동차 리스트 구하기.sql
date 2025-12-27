/*
    테이블)
    CAR_RENTAL_COMPANY_CAR
    CAR_RENTAL_COMPANY_RENTAL_HISTORY
    
    [CAR_RENTAL_COMPANY_CAR]
    자동차의 종류 : '세단', 'SUV', '승합차', '트럭', '리무진'
    옵션 리스트 : 콤마로 구분됨 [정규화..?]  '주차감지센서', '스마트키', '네비게이션', '통풍시트', '열선시트', '후방카메라', '가죽시트' 
    
    문제)
    자동차 종류가 '세단'인 자동차 중에
    10월에 대여를 시작한 기록이 있는
    자동차 ID
    
    
    출력조건)
    중복이 없어야 하며
    내림차순
*/

select
    distinct(C.CAR_ID) as CAR_ID
from
    CAR_RENTAL_COMPANY_CAR C
inner join
    CAR_RENTAL_COMPANY_RENTAL_HISTORY H
on
    C.CAR_ID = H.CAR_ID
where
    month(H.start_date) = 10
    and
    C.CAR_TYPE = '세단'
order by
    CAR_ID desc