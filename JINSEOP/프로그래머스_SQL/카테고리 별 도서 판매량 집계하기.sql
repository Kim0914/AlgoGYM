SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK JOIN BOOK_SALES ON BOOK.BOOK_ID = BOOK_SALES.BOOK_ID
WHERE YEAR(SALES_DATE) = 2022 AND MONTH(SALES_DATE) = 1
GROUP BY CATEGORY
ORDER BY CATEGORY ASC

// JOIN에 대해서 조금 더 생각해보자.
