/*
    테이블)
    ITEM_INFO
    ITEM_TREE
    
    아이템들은 오직 하나의 parent ID를 가진다.
    root의 parent ID -> NULL
    ROOT아이템은 무조건 있음
    
    조건)
    root 아이템의
    ID, ITEM_NAME을 출력해라
    
    정렬)
    아이템 ID asc
*/

select
    I.ITEM_ID, I.ITEM_NAME
from
    ITEM_INFO I
inner join
    ITEM_TREE T
on
    I.ITEM_ID = T.ITEM_ID
where
    isnull(T.PARENT_ITEM_ID)
order by
    I.ITEM_ID asc
    