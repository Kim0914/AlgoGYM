SELECT ID, CASE WHEN sub_a.CHILD_COUNT IS NULL THEN 0
                ELSE sub_a.CHILD_COUNT END AS CHILD_COUNT
FROM ECOLI_DATA ed LEFT OUTER JOIN(SELECT PARENT_ID, COUNT(PARENT_ID) AS CHILD_COUNT
                                FROM ECOLI_DATA
                                GROUP BY PARENT_ID) sub_a
                    ON ed.ID = sub_a.PARENT_ID

#################### 이렇게 IFNULL도 쓸 수 있다.
  
SELECT ID, IFNULL(CHILD_COUNT, 0) AS CHILD_COUNT
FROM ECOLI_DATA ed LEFT OUTER JOIN(SELECT PARENT_ID, COUNT(PARENT_ID) AS CHILD_COUNT
                                FROM ECOLI_DATA
                                GROUP BY PARENT_ID) sub_a
                    ON ed.ID = sub_a.PARENT_ID
