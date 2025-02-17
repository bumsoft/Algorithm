-- 코드를 입력하세요
SELECT count(name)
from (select distinct name from animal_ins) a;