-- 코드를 작성해주세요
/*
2번 형질은 없고 1번 || 3번 형질 보유 개체 수

2로 비트 엔드 연산에서 나오는 값이 아니면 됨
*/

select count(id)  as count
from ecoli_data
where genotype & 2 = 0
and (genotype & 3 or genotype & 4)