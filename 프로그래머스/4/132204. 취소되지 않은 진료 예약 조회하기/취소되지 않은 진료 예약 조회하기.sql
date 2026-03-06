-- 코드를 입력하세요
SELECT a.apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from APPOINTMENT a join doctor d on a.mddr_id = d.dr_id join patient p on a.pt_no = p.pt_no
where year(APNT_YMD) = 2022 and month(APNT_YMD) = 4 and day(APNT_YMD) = 13
    and APNT_CNCL_YN = 'N' and a.mcdp_cd = 'CS'
order by a.apnt_ymd asc;