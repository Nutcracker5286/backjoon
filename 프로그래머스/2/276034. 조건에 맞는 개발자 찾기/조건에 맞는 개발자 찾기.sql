-- 코드를 작성해주세요
/*
id, 이메일, 이름 ,성
개발자 테이블에서 파이썬 또는 c#

이진수 비트 연산으로 추출 
개발자의 스킬 코드 & 서브쿼리 스킬코드에서 파이선
c#
*/
select d.id, d.email, d.first_name,d.last_name
from developers d
where d.skill_code  & (select code from skillcodes where name = 'Python' )
or d.skill_code  & (select code from skillcodes where name = 'C#' )
order by id
