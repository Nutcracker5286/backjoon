-- 코드를 작성해주세요
/*
ntile 함수 , over 윈도우 함수
*/
select id, 
case
    when per = 1 then 'CRITICAL'
    when per =2 then 'HIGH'
    when per =3 then 'MEDIUM'
    else 'LOW'
    end as colony_name
from (select id, ntile(4) over(order by size_of_colony desc) as per
     from ecoli_data) as sub
     order by id 