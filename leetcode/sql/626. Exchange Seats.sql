/*
    Table)
        Seat

    seat id를 swap을 해라
    student가 홀수 인 경우 swap은 안한다?

    정렬)
        id asc  
*/

SELECT
    CASE
        WHEN id % 2 = 1 AND id != (SELECT MAX(id) FROM Seat) THEN id + 1
        WHEN id % 2 = 0 THEN id - 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;