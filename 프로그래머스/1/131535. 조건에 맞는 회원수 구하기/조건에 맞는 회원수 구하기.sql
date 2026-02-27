-- 코드를 입력하세요
SELECT count(*)
from user_info
where joined >= '2021-00-00'
and    joined <'2022-00-00'
and age >= 20
and age<30