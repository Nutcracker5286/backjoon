/*
식품분류별, 가격이 제일 비싼
분류, 가격, 이름 조회
단 과자, 국, 김치, 식용유인 경우만 출력
가격 기준 내림차순 

서브쿼리로 비싼 가격의 제품을 분류해서 거기서 조인해야함
그냥 제품이름 뽑을 시는 잘못된 이름 출력 가능 
*/

SELECT F.CATEGORY, P.MAX_PRICE, F.PRODUCT_NAME
FROM FOOD_PRODUCT F
JOIN (SELECT CATEGORY, MAX(PRICE) AS MAX_PRICE 
     FROM FOOD_PRODUCT
     GROUP BY CATEGORY
     ) P
ON F.PRICE =P.MAX_PRICE
WHERE F.CATEGORY IN ('과자','국','김치','식용유')
GROUP BY F.CATEGORY
ORDER BY MAX_PRICE DESC