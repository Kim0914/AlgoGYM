SELECT ANIMAL_ID, NAME, 
            IF(SEX_UPON_INTAKE IN ('Neutered Male','Spayed Female'),'O','X')
FROM ANIMAL_INS;