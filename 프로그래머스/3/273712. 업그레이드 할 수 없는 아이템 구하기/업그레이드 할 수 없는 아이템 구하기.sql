-- 코드를 작성해주세요
select a.item_id, c.item_name, c.rarity
from item_tree a
left join item_tree b on a.item_id = b.parent_item_id
join item_info c on a.item_id = c.item_id
where b.item_id is null
order by a.item_id desc;