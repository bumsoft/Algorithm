select A.ID AS ID, count(B.id) as CHILD_COUNT
from ecoli_data A
left join ecoli_data B on A.id = B.parent_id
group by A.id