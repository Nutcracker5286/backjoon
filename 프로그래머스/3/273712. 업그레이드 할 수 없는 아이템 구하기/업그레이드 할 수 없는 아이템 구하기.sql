/*
업글 불가 아이템의 아읻, 이름, 희귀도 출력
id 기준 오름차

업글 불가는 자식이 없는 아이템, 개체 아이디가 부모 아이디가 아니면 됨
*/
SELECT F.ITEM_ID, F.ITEM_NAME, F.RARITY
FROM ITEM_INFO F
WHERE NOT EXISTS (
    SELECT 1
    FROM ITEM_TREE T
    WHERE F.ITEM_ID = T.PARENT_ITEM_ID
    
)
ORDER BY ITEM_ID DESC