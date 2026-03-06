-- 1 2 3 | 4 5 6 | 7 8 9 | 10 11 12
select quarter, count(*) as ecoli_count
from(
select
id, DIFFERENTIATION_DATE,
case
    when month(DIFFERENTIATION_DATE) >= 10 then '4Q'
    when month(DIFFERENTIATION_DATE) >= 7 then '3Q'
    when month(DIFFERENTIATION_DATE) >= 4 then '2Q'
    else '1Q'
end as quarter
from ecoli_data) t
group by quarter
order by quarter asc;