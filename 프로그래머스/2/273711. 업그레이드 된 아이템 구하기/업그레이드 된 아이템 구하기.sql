-- 코드를 작성해주세요
select c.item_id, c.item_name, c.rarity
from item_info c
join item_tree t
on c.item_id = t.item_id
where t.parent_item_id in
(select item_id from item_info where rarity='RARE')
order by item_id desc
