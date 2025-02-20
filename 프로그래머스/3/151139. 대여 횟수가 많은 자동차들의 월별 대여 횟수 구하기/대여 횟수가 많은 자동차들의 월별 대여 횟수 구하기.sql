-- 코드를 입력하세요
with total_ as(
SELECT CAR_ID
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date >= '2022-08-01' and start_date < '2022-11-01'
group by car_id
having count(car_id) >= 5)
(SELECT 8 as MONTH, CAR_ID, count(car_id) as RECORDS
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date >= '2022-08-01' and start_date < '2022-09-01'
     	and CAR_ID in (select car_id from total_)
group by car_id
UNION
SELECT 9 as MONTH, CAR_ID, count(car_id) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date >= '2022-09-01' and start_date < '2022-10-01'
 		and CAR_ID in (select car_id from total_)
group by car_id
UNION
SELECT 10 as MONTH, CAR_ID, count(car_id) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date >= '2022-10-01' and start_date < '2022-11-01'
    and CAR_ID in (select car_id from total_)
group by car_id) order by MONTH asc, CAR_ID desc;
