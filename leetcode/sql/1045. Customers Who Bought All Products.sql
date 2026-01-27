/*
    Table)
        Customer
        Product
*/



select
    C.customer_id
from
    (select 
        distinct(customer_id),
        product_key
    from
        Customer) C
group by
    C.customer_id
having
    count(*) = (select count(*) from Product)