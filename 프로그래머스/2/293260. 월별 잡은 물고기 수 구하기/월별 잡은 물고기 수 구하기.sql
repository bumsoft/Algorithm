-- 코드를 작성해주세요

select count(month) as FISH_COUNT, month
from
    (select month(time) month
    from FISH_INFO) t
group by month
order by month asc;