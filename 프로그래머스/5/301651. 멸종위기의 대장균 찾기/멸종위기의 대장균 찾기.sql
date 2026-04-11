/*
세대별 자식이 없는 개체의 수와 세대 출력
즉 해당 개체의 아이디가  페런트 아이디에 없어야 함

재귀로 세대별 데이터 만들어 놓고
기본 데이터와 조인해서 해당 개체의 아이가 페런트 아이디에 없어야 함
*/

WITH RECURSIVE GENERATION_INFO AS (
    # 시작점 부모 세대
    SELECT ID, PARENT_ID , 1 AS GENERATION
    FROM ECOLI_DATA 
    WHERE PARENT_ID IS NULL
    
    UNION ALL
    
    # 부모 세대 기점 자식 추가
    SELECT E.ID, E.PARENT_ID , G.GENERATION+1
    FROM ECOLI_DATA E
    JOIN GENERATION_INFO G
    ON E.PARENT_ID = G.ID
)

# 자식이 없느 개체의 수, 세대 출력, 세대에 대해 오름차순
SELECT COUNT(G.ID) AS COUNT ,G.GENERATION
FROM GENERATION_INFO G
WHERE NOT EXISTS (
SELECT 1
    FROM ECOLI_DATA E
    WHERE E.PARENT_ID = G.ID
)
GROUP BY G.GENERATION
ORDER BY G.GENERATION