-- 조회수가 가장 높은 게시물 id를 뽑는다.
select concat('/home/grep/src/', a.board_id,'/',file_id,file_name,file_ext) as file_path
from used_goods_file a join
(select board_id, rank() over(order by views desc) as r
from USED_GOODS_BOARD) b
on a.board_id = b.board_id
where b.r = 1
order by file_id desc;