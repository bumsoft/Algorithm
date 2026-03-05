-- 코드를 입력하세요
select date_format(sales_date, "%Y-%m-%d"), product_id, user_id, sales_amount
from
(SELECT 
    sales_date,
    product_id,
    user_id,
    sales_amount
from online_sale
where year(sales_date) = 2022 and month(sales_date) = 3

union all

select
    sales_date,
    product_id,
    null,
    sales_amount
from offline_sale
where year(sales_date) = 2022 and month(sales_date) = 3) t
order by sales_date asc, product_id asc, user_id asc;