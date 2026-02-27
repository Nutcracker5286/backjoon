-- 코드를 작성해주세요
/*
부모의 형질을 모두 보유한  id , 형질, 부모의 형질
id 오름차순

id 부모 아이디 이너 조인 
 형질 비트 연산 부모 형질 
*/

select c.id, c.genotype , 
(select genotype from ecoli_data where id = c.parent_id) as parent_genotype
from ecoli_data c
inner join ecoli_data p
on c.parent_id = p.id
where c.genotype & p.genotype = p.genotype
order by id
