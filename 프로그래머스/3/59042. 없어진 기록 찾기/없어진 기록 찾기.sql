-- 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회
SELECT animal_id, name
from animal_outs
where animal_id not in (select animal_id from animal_ins)
order by animal_id, name;