-- 코드를 작성해주세요
-- 2번 x: 0010 : 2
-- 1, 3 o: 0101 : 5
-- 0010

select count(*) as COUNT
from ecoli_data
where (genotype & 2 = 0) and (genotype & 5 > 0);