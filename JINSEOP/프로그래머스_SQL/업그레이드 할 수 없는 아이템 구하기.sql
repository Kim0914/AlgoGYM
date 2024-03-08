SELECT ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO
WHERE ITEM_ID NOT IN (SELECT PARENT_ITEM_ID
                      FROM ITEM_TREE
                      WHERE PARENT_ITEM_ID IS NOT NULL)
ORDER BY ITEM_ID DESC

#####################################################

SELECT ii.ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO as ii LEFT JOIN ITEM_TREE as it 
               ON ii.ITEM_ID = it.PARENT_ITEM_ID
WHERE it.PARENT_ITEM_ID IS NULL
ORDER BY ii.ITEM_ID DESC

# LEFT JOIN을 통해서 푼 풀이
# LEFT JOIN을 하게 되면, ITEM_ID 중 PARENT_ITEM_ID가 없는 row는 NULL이 된다.
# 따라서 IS NULL을 하게 되면, PARENT_ITEM_ID에 없는, 즉 업그레이드 불가능한 아이템이 나옴
