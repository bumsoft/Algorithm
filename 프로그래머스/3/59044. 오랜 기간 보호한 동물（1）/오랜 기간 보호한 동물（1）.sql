-- 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회

select name, datetime
from animal_ins
where animal_id not in( SELECT A.animal_id
                        from Animal_ins A join animal_outs B on A.animal_id = B.animal_id)
order by datetime asc
limit 3;