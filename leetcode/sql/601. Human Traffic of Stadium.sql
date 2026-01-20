SELECT 
    base.id,
    base.visit_date,
    base.people
FROM (
    SELECT
        S.id,
        S.visit_date,
        S.people,
        (S.id - ROW_NUMBER() OVER (ORDER BY S.id)) AS tmp
    FROM Stadium S
    WHERE S.people >= 100
) base
WHERE tmp IN (
    SELECT tmp
    FROM (
        SELECT
            S.id,
            (S.id - ROW_NUMBER() OVER (ORDER BY S.id)) AS tmp
        FROM Stadium S
        WHERE S.people >= 100
    ) x
    GROUP BY tmp
    HAVING COUNT(*) >= 3
)
ORDER BY visit_date;
