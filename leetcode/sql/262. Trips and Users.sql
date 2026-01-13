/*
    table)
        Trips
        Users
    
    cancellation = unbanned user's total / 
            unbanned user's canceled
    
    client and driver must not be banned

    between '2013-10-01' and '2013-10-03'

    Round two decimal point

    driver_id = users_id
*/

SELECT
    t.request_at AS `Day`,
    ROUND(
        SUM(CASE WHEN t.status <> 'completed' THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips t
JOIN Users c
  ON c.users_id = t.client_id
 AND c.banned = 'No'
JOIN Users d
  ON d.users_id = t.driver_id
 AND d.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;
