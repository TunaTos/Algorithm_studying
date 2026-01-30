/*
    테이블)
        Users
        Orders
        Item
            Users.user_id <-> Orders.buyer_id
            Orders.item_id <-> Items.item_id
    
    
*/

select
    Users.user_id as 'buyer_id',
    Users.join_date,
    sum(
            case
            when  
                year(order_date) = 2019
            then 
                1
            else
                0
            end
            ) as 'orders_in_2019'
from
    Users
left join
    Orders
on
    Users.user_id = Orders.buyer_id
group by
    Users.user_id
order by
    1