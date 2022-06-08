-- 코드를 입력하세요
SELECT ANIMAL_TYPE, count(ANIMAL_TYPE) count
FROM ANIMAL_INS a
# WHERE a.ANIMAL_TYPE = "Cat" or a.ANIMAL_TYPE = "Dog"
group by ANIMAL_TYPE
order by ANIMAL_TYPE