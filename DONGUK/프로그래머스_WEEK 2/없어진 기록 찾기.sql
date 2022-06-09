-- 코드를 입력하세요
SELECT o.ANIMAL_ID, o.NAME
FROM ANIMAL_OUTS o
WHERE not exists (select 1 from ANIMAL_INS i where i.animal_id = o.animal_id)