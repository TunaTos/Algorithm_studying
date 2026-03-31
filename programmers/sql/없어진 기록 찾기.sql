/*
table
    ANIMAL_INS
    ANIMAL_OUTS

ANIMAL_ID -> 외래 키

입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는
    동물의 ID, 동물의 이름
    ID순으로

풀이방법
    - IN과 OUT이 모두 있는 NAME을 구한다
    - not in 연산자로 출력한다
    
explain
id	select_type	table	partitions	type	possible_keys	key	key_len	ref	rows	filtered	Extra
1	SIMPLE	O		index		PRIMARY	23		100	100	
1	SIMPLE			eq_ref			24	sql_runner_run.O.ANIMAL_ID	1	100	Using where; Not exists
2	MATERIALIZED	ANIMAL_INS		index	PRIMARY	PRIMARY	23		100	100	Using index

not in을 join으로 최적화
*/

select 
    O.ANIMAL_ID as ANIMAL_ID,
    O.NAME as NAME
from
    ANIMAL_OUTS O
where
    O.ANIMAL_ID not in (select ANIMAL_ID from ANIMAL_INS)
order by
    ANIMAL_ID