SELECT TA.AUTHOR_ID, AUTHOR_NAME, CATEGORY, TOTAL_SALES
FROM (SELECT BOOK_SALES.BOOK_ID, AUTHOR_ID, CATEGORY, 
      SUM(PRICE * SALES) AS TOTAL_SALES
      FROM BOOK_SALES JOIN BOOK ON BOOK_SALES.BOOK_ID = BOOK.BOOK_ID
      WHERE YEAR(SALES_DATE) = 2022 AND MONTH(SALES_DATE) = 1
      GROUP BY BOOK.AUTHOR_ID, BOOK.CATEGORY) AS TA 
      JOIN AUTHOR ON TA.AUTHOR_ID = AUTHOR.AUTHOR_ID
ORDER BY TA.AUTHOR_ID, CATEGORY DESC

// 문제 이해하기가 조금 힘들었다.
