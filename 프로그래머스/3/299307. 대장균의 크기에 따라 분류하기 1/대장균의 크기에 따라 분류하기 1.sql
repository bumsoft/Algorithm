-- 100 이하라면 'LOW', 100 초과 1000 이하라면 'MEDIUM', 1000 초과라면 'HIGH' 라고 분류
select id, 
    case
        when size_of_colony > 1000 then 'HIGH'
        when size_of_colony > 100 then 'MEDIUM'
        else 'LOW'
    end
    as size
from ecoli_data
order by id asc;