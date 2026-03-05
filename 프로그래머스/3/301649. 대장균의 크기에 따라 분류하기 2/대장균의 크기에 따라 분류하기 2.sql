-- 코드를 작성해주세요
select id,
case when (row_number() over(order by size_of_colony desc)) / count(*) over() * 100 <=25 then 'CRITICAL'
    when (row_number() over(order by size_of_colony desc)) / count(*) over() * 100  <= 50 then 'HIGH'
    when (row_number() over(order by size_of_colony desc)) / count(*) over() * 100  <=75 then 'MEDIUM'
    else 'LOW'
    end as colony_name
from ecoli_data
order by id asc;