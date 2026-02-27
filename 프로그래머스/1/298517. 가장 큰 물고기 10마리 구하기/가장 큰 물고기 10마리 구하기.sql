-- 코드를 작성해주세요
/*
id , length

가장 큰, 10개
길이 내림, id 오름
*/

select id, length
from fish_info
order by length desc, id asc
limit 10
