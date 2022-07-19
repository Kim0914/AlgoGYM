SELECT PLACES.*
FROM PLACES, (SELECT HOST_ID FROM PLACES
                GROUP BY HOST_ID
                HAVING COUNT(HOST_ID) > 1) AS HEAVY
WHERE PLACES.HOST_ID LIKE HEAVY.HOST_ID
ORDER BY PLACES.ID