-- 코드를 작성해주세요
/*
물고기의 수 출력
길이가 10 이하
*/

select count(id)  as fish_count
from fish_info
where length is null