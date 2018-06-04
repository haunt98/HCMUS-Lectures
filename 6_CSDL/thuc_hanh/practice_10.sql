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

-- Cho  biết  tên  những  giáo  viên  khoa  Công  nghệ  thông  tin. 
select gv.hoten
from giaovien gv join bomon bm on gv.mabm = bm.mabm
	join khoa k on bm.makhoa = k.makhoa
where k.tenkhoa = N'Công nghệ thông tin';