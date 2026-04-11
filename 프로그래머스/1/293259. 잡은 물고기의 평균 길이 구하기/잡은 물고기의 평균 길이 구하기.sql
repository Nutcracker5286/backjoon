/*
물고기 평균 길이 출력 특정 명으로 출력
10cm 이하는 null이기에 10cm로 변환 후 출력
*/
SELECT ROUND(AVG(COALESCE(LENGTH,10)),2) AS AVERAGE_LENGTH
FROM FISH_INFO
