-- COUNT(*) : NULL을 포함하는 모든 행을 센다
-- COUNT(컬럼명) : NULL은 제외하고 카운트한다

WITH RECURSIVE hours AS (
    SELECT 0 AS HOUR       
    
    UNION ALL
    
    SELECT HOUR + 1        
    FROM hours
    WHERE HOUR < 23       
)
SELECT 
    hours.HOUR as HOUR, 
    count(ANIMAL_OUTS.ANIMAL_ID) as COUNT
FROM 
    hours
LEFT JOIN 
    ANIMAL_OUTS
ON
    hours.HOUR = HOUR(ANIMAL_OUTS.DATETIME)
GROUP BY
    hours.HOUR
ORDER BY
    hours.HOUR;