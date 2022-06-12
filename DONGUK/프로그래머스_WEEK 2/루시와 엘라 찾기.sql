-- 코드를 입력하세요
SELECT A.ANIMAL_ID, A.NAME, A.SEX_UPON_INTAKE
FROM ANIMAL_INS A
WHERE A.NAME = 'Lucy' or A.NAME = 'Ella' or A.NAME = 'Pickle' or A.NAME = 'Rogan' or A.NAME = 'Sabrina' or A.NAME = 'Mitty'
ORDER BY A.ANIMAL_ID