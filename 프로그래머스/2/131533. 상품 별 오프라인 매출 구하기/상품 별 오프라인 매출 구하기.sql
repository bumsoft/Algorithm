-- 상품코드 별 매출액(판매가 * 판매량) 합계를 출력
-- product_id로 조인하고, product_code로 group by한 뒤, sum*sum
SELECT A.product_code, sum(B.sales_amount)*MAX(A.price) sales
from product A natural join offline_sale B
group by product_code
order by sales desc, product_code asc;