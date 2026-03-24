
/*
Table)
    ANIMAL_INS
    ANIMAL_OUTS

Forein Key)
    ANIMAL_ID

보호 시작일 < 입양일
ANIMAL_ID, NAME
order by)
    보호 시작일

id	select_type	table	partitions	type	possible_keys	key	key_len	ref	rows	filtered	Extra
1	SIMPLE	I		ALL	PRIMARY				100	100	Using filesort
1	SIMPLE	O		eq_ref	PRIMARY	PRIMARY	23	sql_runner_run.I.ANIMAL_ID	1	33.33	Using where

*/

explain
select
    I.ANIMAL_ID as 'ANIMAL_ID',
    I.NAME as 'NAME'
from
    ANIMAL_INS I
inner join
    ANIMAL_OUTS O
on
    I.ANIMAL_ID = O.ANIMAL_ID
where
    I.DATETIME > O.DATETIME
order by
    I.DATETIME
