/*
    PATIENT
    
    DOCTOR
    
    APPOINTMENT
    
    3개의 테이블에서
    2022년 4월 13일, 취소되지 않은 -> N,  흉부외과 진료 예약 내역 -> MCDP_CD = 'CS'
    
    진료 예약 번호, 환자 이름, 환자번호, 진료과코드, 읙사 이름, 진료예약일시
    
    order
    진료예약일시 (오름차순)
*/
select 
    A.APNT_NO,
    P.PT_NAME,
    P.PT_NO,
    D.MCDP_CD,
    D.DR_NAME,
    A.APNT_YMD
from
    APPOINTMENT A
inner join 
    DOCTOR D
on
    D.DR_ID = A.MDDR_ID
inner join
    PATIENT P
on
    P.PT_NO = A.PT_NO
where
    A.MCDP_CD = 'CS'
    and
    A.APNT_CNCL_YN = 'N'
    and
    A.APNT_YMD >= '2022-04-13'
    and
    A.APNT_YMD < '2022-04-14'
order by
    APNT_YMD asc