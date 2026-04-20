/*
특정 날짜에 대여중인 자동차인 경우 대여중 표시, 아니면 대여 가능 표시
반납날짜가 동일 시 대여중으로 표시
컬럼 변경 , id 기준 정렬

대여가능 테이블 생성후 출력

여러 기록 중에서 end date가 날짜 이상이 하나 이상이면 대여중
미만이면 대여가능 표시
*/
SELECT   C.CAR_ID,
CASE # 하나 이상이면 대여중
    WHEN    (SELECT COUNT(*) FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
             WHERE '2022-10-16' BETWEEN START_DATE AND END_DATE
             AND C.CAR_ID = H.CAR_ID
            GROUP BY CAR_ID) >=1 THEN '대여중' 
    ELSE  '대여 가능' 
END AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY C
GROUP BY C.CAR_ID
ORDER BY C.CAR_ID DESC
