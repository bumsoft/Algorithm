-- 코드를 작성해주세요
select a.item_id, b.item_name
from item_tree a
join item_info b on a.item_id = b.item_id
where a.parent_item_id is null
order by a.item_id;