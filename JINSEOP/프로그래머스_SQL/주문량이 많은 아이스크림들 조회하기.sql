SELECT out_tab.FLAVOR
FROM (SELECT FIRST_HALF.FLAVOR, (TOTAL_ORDER + TOTSUM) AS TOTAL
      FROM FIRST_HALF JOIN (SELECT SHIPMENT_ID, FLAVOR, SUM(TOTAL_ORDER) AS TOTSUM
                      FROM JULY
                      GROUP BY FLAVOR) AS in_tab
      ON FIRST_HALF.FLAVOR = in_tab.FLAVOR
      ORDER BY TOTAL DESC
      LIMIT 3) AS out_tab
