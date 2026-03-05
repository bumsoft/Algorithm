-- 코드를 작성해주세요
with recursive rt as(
    select id, parent_id, 1 as gen
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, rt.gen + 1 as gen
    from ecoli_data a
    join rt on a.parent_id = rt.id
)
select count(a.gen) as count, a.gen as generation
from rt a
left join rt b on a.id = b.parent_id
where b.id is null
group by a.gen
order by generation asc;
