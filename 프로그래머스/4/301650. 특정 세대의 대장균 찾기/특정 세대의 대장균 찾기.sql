-- 코드를 작성해주세요
select a.id
from ecoli_data a
join ecoli_data b on a.parent_id = b.id
join ecoli_data c on b.parent_id = c.id
where c.parent_id is null
order by a.id asc;