/*
각 시간대별로 입양이 몇건 발생 했는지 출력
시간대 순으로 정렬

단 없는 시간대에 경우 출력이 안되므로 재귀를 이용해서 미리 시간대 테이블 생성
이와 left join 시행
*/
WITH RECURSIVE HOURS AS (
    SELECT  0 AS HOUR
    
    UNION ALL
    SELECT HOUR+1
    FROM HOURS
    WHERE HOUR < 23
)

SELECT H.HOUR, COUNT(A.ANIMAL_ID) AS COUNT
FROM HOURS H
LEFT JOIN ANIMAL_OUTS A
ON H.HOUR = HOUR(DATETIME) 
GROUP BY H.HOUR
ORDER BY H.HOUR