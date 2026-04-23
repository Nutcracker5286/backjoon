/*
2022.08부터 2022.10까지 총 대여 횟수가 5회 이상인 자동차 필터
해당 기간 동안의 월별 자동차 id 별 총 대여 횟수 출력
월 기준 오름차, id 기준 내림차, 대여횟수 0번이면 결과 제외

id별 해당 기간동안의 대여횟수가 5회 이상인 자동차 테이블 생성
일치하는 id로 조인 하고 월별, id별 개수 출력
*/
SELECT MONTH(H.START_DATE) AS MONTH, H.CAR_ID, COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
JOIN (
    SELECT CAR_ID, COUNT(*) AS R
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE >= '2022-08-01'
    AND START_DATE < '2022-11-01'
    GROUP BY CAR_ID
    HAVING COUNT(*) >=5
     ) S
ON H.CAR_ID =S.CAR_ID
WHERE H.START_DATE >= '2022-08-01'
  AND H.START_DATE < '2022-11-01'
GROUP BY MONTH(H.START_DATE),H.CAR_ID
ORDER BY MONTH, H.CAR_ID DESC