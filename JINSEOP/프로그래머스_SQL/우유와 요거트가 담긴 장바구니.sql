SELECT CART_ID
FROM CART_PRODUCTS
WHERE NAME = 'Milk' AND CART_ID IN(SELECT CART_ID
                                FROM CART_PRODUCTS
                                WHERE NAME = 'Yogurt')
ORDER BY CART_ID

// IN ANY ALL에 대한 이해가 필요하다.
