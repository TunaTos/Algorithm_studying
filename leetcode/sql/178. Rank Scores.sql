/*
    Table
        Scores  

    rank
        (high -> low)
    rank -> dense rank  
*/

select
    score,
    dense_rank() over(order by score desc) as 'rank'
from
    Scores;

# over 안에는 partition, order by 함수만 들어갈 수 있다.