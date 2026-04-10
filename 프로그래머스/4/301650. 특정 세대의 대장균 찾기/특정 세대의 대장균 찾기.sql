-- 코드를 작성해주세요
/*
3세대의 id 출력, id 오름차순

손자 자식 부모 조인, 3세대만 출력해야 하기 때문에 부모는 반드시 null
*/
SELECT C.ID
FROM ECOLI_DATA C
JOIN ECOLI_DATA P
ON C.PARENT_ID = P.ID
JOIN ECOLI_DATA G
ON P.PARENT_ID = G.ID
WHERE G.PARENT_ID IS NULL