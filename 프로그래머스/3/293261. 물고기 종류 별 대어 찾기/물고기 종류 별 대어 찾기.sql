-- 코드를 작성해주세요
select id, fish_name, length
from fish_info A natural join fish_name_info B join (select fish_type, max(length) m from fish_info group by fish_type) C 
                    on A.fish_type = C.fish_type
where A.length = C.m
order by id asc;