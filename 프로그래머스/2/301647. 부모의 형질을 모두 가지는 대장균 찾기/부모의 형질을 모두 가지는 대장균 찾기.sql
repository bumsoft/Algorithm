select
A.id, A.genotype, B.genotype
from ecoli_data A left join ecoli_data B on A.parent_id = B.id
where A.genotype & B.genotype = B.genotype

order by A.id asc;
