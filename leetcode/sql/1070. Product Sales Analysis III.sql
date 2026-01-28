/*
    table)
        Sales

    각각의 product_id 마다 가장 최신의 year를 출력하라
    모든 sales entiry를 출력하라
    출력 순서는 상관 없다
*/

select
    product_id,
    year  as 'first_year',
    quantity,
    price
from
    Sales
where
    (product_id, year) in (
        select
            product_id,
            min(year)
        from
            Sales
        group by
            product_id
    )