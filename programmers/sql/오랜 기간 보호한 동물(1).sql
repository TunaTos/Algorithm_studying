/*
테이블)
ANIMAL_INS
ANIMAL_OUTS

입양을 가지 못한 동물 중,
가장 오래 보호소에 있던 동물 3마리
이름, 보호 시작일
정렬 -> 보호 시작일


id	select_type	table	partitions	type	possible_keys	key	key_len	ref	rows	filtered	Extra
1	SIMPLE	I	null	ALL	null	null	null	null	100	100	Using filesort
1	SIMPLE		null	eq_ref			24	mysql_run_002.I.ANIMAL_ID	1	100	Using where; Not exists
2	MATERIALIZED	ANIMAL_OUTS	null	index	PRIMARY	PRIMARY	23	null	100	100	Using index


*/

select
    I.NAME,
    I.DATETIME
from
    ANIMAL_INS I    
where
    I.ANIMAL_ID not in (select ANIMAL_ID from ANIMAL_OUTS)
order by
    2
limit
    3
    
