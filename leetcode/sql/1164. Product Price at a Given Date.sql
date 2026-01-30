
SELECT
    p.product_id,
    IFNULL(last_price.new_price, 10) AS price
FROM
    (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN
    (
        SELECT
            x.product_id,
            pr.new_price
        FROM
            (
                SELECT
                    product_id,
                    MAX(change_date) AS change_date
                FROM Products
                WHERE change_date <= '2019-08-16'
                GROUP BY product_id
            ) x
        INNER JOIN Products pr
            ON pr.product_id = x.product_id
           AND pr.change_date = x.change_date
    ) last_price
    ON last_price.product_id = p.product_id;
