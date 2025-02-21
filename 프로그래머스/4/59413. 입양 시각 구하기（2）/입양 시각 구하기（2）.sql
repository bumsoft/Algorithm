with hours as(
select 0 as HOUR
UNION
select 1 as HOUR
UNION
select 2 as HOUR
UNION
select 3 as HOUR
UNION
select 4 as HOUR
UNION
select 5 as HOUR
UNION
select 6 as HOUR
UNION
select 7 as HOUR
UNION
select 8 as HOUR
UNION
select 9 as HOUR
UNION
select 10 as HOUR
UNION
select 11 as HOUR
UNION
select 12 as HOUR
UNION
select 13 as HOUR
UNION
select 14 as HOUR
UNION
select 15 as HOUR
UNION
select 16 as HOUR
UNION
select 17 as HOUR
UNION
select 18 as HOUR
UNION
select 19 as HOUR
UNION
select 20 as HOUR
UNION
select 21 as HOUR
UNION
select 22 as HOUR
UNION
select 23 as HOUR
),
temp1 as (SELECT cast(substr(datetime,12,2) as unsigned) as HOUR
from animal_outs)

select hours.HOUR, coalesce(COUNT,0) as COUNT
from hours left join (
    select HOUR, count(hour) as COUNT
    from temp1
    group by HOUR) t
    on hours.hour = t.hour
order by hours.hour;
    
    
    