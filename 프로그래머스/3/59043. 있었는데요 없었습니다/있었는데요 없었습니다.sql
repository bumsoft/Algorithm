-- 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회
-- 보호 시작일이 빠른 순으로 조회
SELECT A.animal_id, A.name
from animal_ins A join animal_outs B on A.animal_id = B.animal_id
where A.datetime > B.datetime
order by A.datetime asc