-- 코드를 작성해주세요
/*
100 이하 low, 100 ~ 1000 medium, 1000 초과 high
id와 분류 출력
*/
select id ,
case when size_of_colony <=100 then 'LOW'
when size_of_colony <= 1000 then 'MEDIUM'
Else 'HIGH'
end as size
from ecoli_data
order by id