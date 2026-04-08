-- 코드를 작성해주세요
/*
파이선이나 c# 스킬을 가져야함
아이디 이메일 이름 성 
*/
SELECT D.ID, D.EMAIL, D.FIRST_NAME, D.LAST_NAME
FROM DEVELOPERS D
# 비트 엔드 연산시 
WHERE D.SKILL_CODE & 
(SELECT SUM(CODE) FROM SKILLCODES WHERE NAME IN ('Python' , 'C#'))
ORDER BY ID