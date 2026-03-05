-- 1 또는 3 보유
select count(*) as count
from ecoli_data
where genotype & 2 = 0 and (genotype & 1 <> 0 or genotype & 4 <> 0);