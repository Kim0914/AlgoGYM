SELECT CAR_ID, 
       CASE WHEN MAX(end_date) >= '2022-10-16' THEN '대여중' # 끝나지 않았으면 대여중
       ELSE '대여 가능' END AS AVAILABILITY # 아니면 대여 가능
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE start_date <= '2022-10-16' # 2022-10-16 이전에 대여한 것 중에
GROUP BY CAR_ID
ORDER BY CAR_ID desc
