use QuanLyDeTai;
go

--Cho  biết  mã  của  các  giáo  viên  có  họ  tên  bắt  đầu  là  “Nguyễn”  và  lương  trên  $2000  hoặc, 
--giáo  viên  là  trưởng  bộ  môn  nhận  chức  sau  năm  1995. 
(select magv 
from giaovien 
where luong > 2000 and hoten like N'Nguyễn%')
union
(select gv.magv
from giaovien gv join bomon bm on gv.magv = bm.truongbm
where year(bm.NGAYNHANCHUC)> 1995 );

--Cho  biết  tên  những  giáo  viên  khoa  Công  nghệ  thông  tin. 
select gv.hoten
from giaovien gv join bomon bm on gv.mabm = bm.mabm
	join khoa k on bm.makhoa = k.makhoa
where k.tenkhoa = N'Công nghệ thông tin';

--Cho  biết  thông  tin  của  bộ  môn  cùng  thông  tin  giảng  viên  làm  trưởng  bộ  môn  đó. 
select *
from bomon bm left join giaovien gv on bm.TRUONGBM = gv.MAGV

--Với  mỗi  giáo  viên,  hãy  cho  biết  thông  tin  của  bộ  môn  mà  họ  đang  làm  việc. 
select *
from GIAOVIEN gv left join BOMON bm on gv.MABM = bm.MABM

--Cho  biết  tên  người  chủ  nhiệm  đề  tài  của  những  đề  tài  thuộc  chủ  đề  Quản  lý  giáo  dục. 
select gv.*
from GIAOVIEN gv join DETAI d on gv.magv = d.MADT 
	join CHUDE c on d.MACD = c.MACD
where c.TENCD = N'Quản lý giáo dục'

--Cho  biết  số  lượng  giáo  viên  viên  và  tổng  lương  của  họ. 
select count(*), sum(LUONG)
from GIAOVIEN

--Cho  biết  số  lượng  giáo  viên  và  lương  trung  bình  của  từng  bộ  môn. 
select mabm, count(magv), avg(LUONG)
from GIAOVIEN gv
group by gv.MABM

--Cho  biết  tên  chủ  đề  và  số  lượng  đề  tài  thuộc  về  chủ  đề  đó. 
select c.TENCD, count(d.MADT)
from DETAI d join CHUDE c on d.MACD = c.MACD
group by d.macd, c.TENCD

--Cho  biết  tên  giáo  viên  và  số  lượng  đề  tài  mà  giáo  viên  đó  tham  gia. 
select gv.HOTEN, count(distinct t.MADT)
from giaovien gv left join THAMGIADT t on gv.MAGV = t.MAGV
group by gv.MAGV, gv.HOTEN

--Cho  biết  tên  giáo  viên  và  số  lượng  đề  tài  mà  giáo  viên  đó  làm  chủ  nhiệm.
select gv.HOTEN, count(distinct d.MADT)
from giaovien gv left join DETAI d on gv.MAGV = d.GVCNDT
group by gv.MAGV, gv.HOTEN

--Cho  biết  tên  những  giáo  viên  đã  tham  gia  từ  1  đề  tài  trở  lên. 
select gv.HOTEN
from giaovien gv join THAMGIADT t on gv.MAGV = t.MAGV
group by gv.MAGV, gv.HOTEN
having count(distinct t.MADT) >= 1

--Cho  biết  mức  lương  cao  nhất  của  các  giảng  viên.
select max(LUONG)
from GIAOVIEN

select distinct g.LUONG
from GIAOVIEN g
where g.LUONG >= all (
	select g2.LUONG
	from GIAOVIEN g2)

--Cho  biết  những  giáo  viên  có  lương  lớn  nhất.
select g.*
from GIAOVIEN g
where g.LUONG >= all (
	select g2.LUONG
	from GIAOVIEN g2)

--Cho  biết  tên  những  giáo  viên  khoa  Công  nghệ  thông  tin  mà  chưa  tham  gia  đề  tài  nào.
select g.HOTEN
from GIAOVIEN g join BOMON b on g.MABM = b.MABM
	join KHOA k on b.MAKHOA = k.MAKHOA
where k.TENKHOA = N'Công nghệ thông tin' and g.MAGV not in (
	select magv
	from THAMGIADT)

--Tìm  những  trưởng  bộ  môn  tham  gia  tối  thiểu  1  đề  tài 
select distinct g.HOTEN
from GIAOVIEN g join BOMON b on g.MAGV = b.TRUONGBM
	join THAMGIADT t on g.MAGV = t.MAGV

--Cho  biết  tên  giáo  viên  nào  mà  tham  gia  đề  tài  đủ  tất  cả  các  chủ  đề. 
select g.HOTEN
from GIAOVIEN g 
where not exists(
	(select distinct c.MACD 
	from CHUDE c)
	except
	(select distinct d2.MACD
	from GIAOVIEN g2 join THAMGIADT t2 on g2.MAGV = t2.MAGV
		join DETAI d2 on t2.MADT = d2.MADT
	where g2.MAGV = g.MAGV)
)

select g.HOTEN 
from GIAOVIEN g
where not exists(
	select *
	from CHUDE c
	where not exists(
		select *
		from GIAOVIEN g2 join THAMGIADT t on g2.MAGV = t.MAGV
			join DETAI d on t.MADT = d.MADT
		where d.MACD = c.MACD
	)
)

select g.HOTEN
from GIAOVIEN g join THAMGIADT t on g.MAGV = t.MAGV
	join DETAI d on t.MADT = d.MADT
group by g.HOTEN, g.MAGV
having count(distinct d.MACD) = (
	select count(distinct macd)
	from CHUDE
)

--Cho  biết  tên  đề  tài  nào  mà  được  tất  cả  các  giáo  viên  của  bộ  môn  HTTT  tham  gia. 