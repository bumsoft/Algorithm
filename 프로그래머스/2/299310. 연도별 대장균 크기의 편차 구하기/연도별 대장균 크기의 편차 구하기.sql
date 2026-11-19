-- 연도별 가장 큰 대장균 - 각 대장균 크기가 편차임

select year(differentiation_date) as year, B.maxx - A.size_of_colony as year_dev, A.id
from ecoli_data A
left join(
        select year(DIFFERENTIATION_DATE) as year, max(size_of_colony) as maxx
        from ecoli_data
        group by year(DIFFERENTIATION_DATE)
    ) B on year(A.DIFFERENTIATION_DATE) = B.year
order by year asc, year_dev asc;