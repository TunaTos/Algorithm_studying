/*
    테이블)
    아이템 정보 : ITEM_INFO
    아이템 관계 : ITEM_TREE
    
    ---
    아이템은 하나의 parent id를 가진다
    루트 아이템의 parent는 null이다.
    
    root는 무조건 존재한다
    
    ---
    더 이상 업그레이드 할 수 없는 아이템의 
        ID, ITEM_NAME< PARITY
    ID 내림차순
    
    
    a -> b -> c로 갈 때, a를 parent이다.
    
    더 이상 업그레이드 할 수 없는 아이템은 -> leaf node
    업그레이드 할 수 있는 거 -> parent_item_id = ITEM_ID
*/

select
    ITEM_ID, ITEM_NAME, RARITY
from
    ITEM_INFO
where
    ITEM_ID 
    not in 
    (    
        select
            distinct(PARENT_ITEM_ID)
        from
            ITEM_TREE
        where
            PARENT_ITEM_ID is not null
    )
order by
    ITEM_ID desc