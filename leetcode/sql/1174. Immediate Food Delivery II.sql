/*
    Table) Delivery

    pref delivery date = order date
        immediate
    else
        scheduled

    first_order -> order_date중에서 가장 빠른거

    percentage를 2decimal 출력해라

    group by를 하면 집계함수 아닌 거는 랜덤값으로 출력됨!
*/


select
    round(sum(case when d.order_date = d.customer_pref_delivery_date then 1 else 0 end) /
    count(*) * 100, 2) as 'immediate_percentage' 
from
(select
    customer_id,
    order_date,
    customer_pref_delivery_date
from
    Delivery
where
    (customer_id, order_date) in (
        select
            customer_id,
            min(order_date) as 'order_date'
        from
            Delivery
        group by
            customer_id
    )
) d
