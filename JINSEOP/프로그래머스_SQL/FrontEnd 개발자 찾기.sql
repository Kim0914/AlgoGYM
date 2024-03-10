WITH front_end as(
    SELECT SUM(CODE) AS CODE
    FROM SKILLCODES
    GROUP BY CATEGORY
    HAVING CATEGORY = 'Front End'
)

SELECT d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
FROM DEVELOPERS d, front_end
WHERE (d.SKILL_CODE & front_end.CODE) != 0
ORDER BY d.ID

# 아래와 같이 subquery를 이용해서 풀 수도 있음

SELECT d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
FROM DEVELOPERS d, (SELECT SUM(CODE) AS CODE
                    FROM SKILLCODES
                    GROUP BY CATEGORY
                    HAVING CATEGORY = 'Front End') AS front_end
WHERE (d.SKILL_CODE & front_end.CODE) != 0
ORDER BY d.ID

# WITH 문은 위와 같이 SUBQUERY의 재사용성을 높일 수 있는 방법이다.
