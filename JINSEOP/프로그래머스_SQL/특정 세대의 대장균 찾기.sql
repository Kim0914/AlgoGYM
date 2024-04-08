WITH RECURSIVE RECURSIVE_ECOLI as(
    SELECT ID, PARENT_ID, 1 AS GENERATION
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL
    # 기본 틀을 만드는 쿼리, 1세대 대장균들만 모은다
  
    UNION ALL
  
    # 이후 재귀가 돌아가는 구간, JOIN이 필요하다.
    # 재귀를 통해 2, 3, 4 세대의 대장균들이 나오고, 위의 테이블과 UNION 한다.
    SELECT ed.ID, ed.PARENT_ID, re.GENERATION + 1
    FROM ECOLI_DATA ed JOIN RECURSIVE_ECOLI re ON ed.PARENT_ID = re.ID

    # 재귀가 돌며 UNION ALL을 실행해서, 계속 이어붙는다.
    # RECURSIVE 테이블에서 기존 ECOLI_DATA 테이블의 부모를 찾은 뒤, 해당 컬럼의 GENERATION + 1을 한다.
)

SELECT ID
FROM RECURSIVE_ECOLI
WHERE GENERATION = 3
ORDER BY ID
