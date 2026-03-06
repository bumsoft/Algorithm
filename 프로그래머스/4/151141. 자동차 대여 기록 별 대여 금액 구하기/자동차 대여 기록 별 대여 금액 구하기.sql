-- 자동차 종류가 '트럭'인 자동차의 대여 기록 ID와 대여 금액 리스트를 출력
select distinct history_id,
case 
    when dur is null then d * daily_fee
    else daily_fee * ((100-discount_rate)/100) * d + ''

end
as fee
from
(SELECT h.history_id, 
    case
    when datediff(h.end_date, h.start_date)+1 >= 90 then '90일 이상'
    when datediff(h.end_date, h.start_date)+1 >= 30 then '30일 이상'
    when datediff(h.end_date, h.start_date)+1 >= 7 then '7일 이상'
    end as dur,
    datediff(h.end_date, h.start_date)+1 as d,
    p.duration_type, 
    p.discount_rate, 
    c.daily_fee
from CAR_RENTAL_COMPANY_CAR c
join CAR_RENTAL_COMPANY_RENTAL_HISTORY h on c.car_id = h.car_id
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN p on c.car_type = p.car_type
where c.car_type = '트럭'
 ) t
where dur is null or dur = duration_type
order by fee desc, history_id desc;