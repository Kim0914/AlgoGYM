SELECT ii.ITEM_ID, ITEM_NAME, RARITY
FROM (SELECT ITEM_ID
      FROM ITEM_TREE
      WHERE ITEM_TREE.PARENT_ITEM_ID IN (SELECT ITEM_ID
                                         FROM ITEM_INFO
                                         WHERE RARITY = 'RARE')) child
      JOIN ITEM_INFO ii ON ii.ITEM_ID = child.ITEM_ID
ORDER BY ii.ITEM_ID DESC
