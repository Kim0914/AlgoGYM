SELECT FOOD_PRODUCT.PRODUCT_ID, FOOD_PRODUCT.PRODUCT_NAME, 
       SUM(AMOUNT) * PRICE AS TOTAL_SALES
FROM FOOD_PRODUCT JOIN FOOD_ORDER ON FOOD_PRODUCT.PRODUCT_ID = FOOD_ORDER.PRODUCT_ID
WHERE MONTH(PRODUCE_DATE) = 5
GROUP BY FOOD_PRODUCT.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, PRODUCT_ID ASC;
