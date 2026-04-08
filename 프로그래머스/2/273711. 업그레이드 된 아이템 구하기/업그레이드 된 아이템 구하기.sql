-- 코드를 작성해주세요
/*
id , name , rarity 출력
아이템이 희귀도이고, 다음 업그레이드 아이템
즉 부모가 레어인 아이템 출력

트리 , 인포를 id 기준으로 조인
페런트 아이디 가 인포에서 id만 뽑은 서브쿼리에 존재
*/
SELECT I.ITEM_ID, I.ITEM_NAME, I.RARITY
FROM ITEM_INFO I
JOIN ITEM_TREE T
ON I.ITEM_ID = T.ITEM_ID
WHERE T.PARENT_ITEM_ID IN (SELECT ITEM_ID FROM ITEM_INFO WHERE RARITY ='RARE')
ORDER BY I.ITEM_ID DESC;