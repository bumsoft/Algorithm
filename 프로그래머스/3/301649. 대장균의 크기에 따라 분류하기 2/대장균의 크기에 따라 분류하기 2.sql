-- 코드를 작성해주세요
select id, 
        case
        when NTILE(4) OVER(order by size_of_colony desc) = 1 then 'CRITICAL'
        when NTILE(4) OVER(order by size_of_colony desc) = 2 then 'HIGH'
        when NTILE(4) OVER(order by size_of_colony desc) = 3 then 'MEDIUM'
        when NTILE(4) OVER(order by size_of_colony desc) = 4 then 'LOW'
        end as colony_name
from ecoli_data
order by id asc;