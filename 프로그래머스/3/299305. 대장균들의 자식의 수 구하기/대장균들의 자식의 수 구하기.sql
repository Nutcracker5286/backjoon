-- 코드를 작성해주세요
/*
대장균 개체 당 id, 자식의 수  자식이 없다면 자식의 수는 0
id 오름차순 

부모 아이디 , 개체 아이디가 같은
부모 아이디 카운트 해서 자식의 수 세기
*/
select p.id , count(c.id)as child_count
from ecoli_data p
left join ecoli_data c
on p.id = c.parent_id
group by p.id
order by id 