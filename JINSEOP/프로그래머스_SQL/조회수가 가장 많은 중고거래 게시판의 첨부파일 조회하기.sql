SELECT CONCAT("/home/grep/src/", ugf.BOARD_ID, "/", FILE_ID, FILE_NAME, FILE_EXT) AS FILE_PATH
FROM( SELECT *
      FROM (SELECT MAX(VIEWS) as mv
            FROM USED_GOODS_BOARD
            ORDER BY VIEWS DESC) as in_tab, USED_GOODS_BOARD as ugb
      WHERE VIEWS = mv) as out_tab JOIN USED_GOODS_FILE ugf
                                    ON out_tab.BOARD_ID = ugf.BOARD_ID
ORDER BY FILE_ID DESC

-- 좀 바보같은데 쿼리가
