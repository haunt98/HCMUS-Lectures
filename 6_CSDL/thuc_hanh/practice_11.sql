use QuanLyChuyenBay;
go
--Với  mỗi  sân  bay  (SBDEN),  cho  biết  số  lượng  chuyến  bay  hạ  cánh  xuống  sân  bay  đó.  Kết 
--quả  được  sắp  xếp  theo  thứ  tự  tăng  dần  của  sân  bay  đến. 
select SBDEN, count(MACB)
from CHUYENBAY
group by SBDEN
order by SBDEN

--Với  mỗi  sân  bay  (SBDI),  cho  biết  số  lượng  chuyến  bay  xuất  phát  theo  từng  ngày.  Xuất 
--ra  mã  sân  bay  đi,  ngày  và  số  lượng.
select c.SBDI, l.NGAYDI, count(c.MACB)
from CHUYENBAY c join LICHBAY l on c.MACB = l.MACB
group by c.SBDI, l.NGAYDI
order by c.SBDI

--Với  mỗi  lịch  bay,  cho  biết  mã  chuyến  bay,  ngày  đi  cùng  với  số  lượng  nhân  viên  không 
--phải  là  phi  công  của  chuyến  bay  đó. 
select l.MACB, l.NGAYDI, count (p.manv)
from lichbay l join PHANCONG p on (l.MACB = p.MACB and l.NGAYDI = p.NGAYDI)
	join NHANVIEN n on p.manv = n.MANV
where n.LOAINV = 0
group by l.macb, l.NGAYDI

--Cho  biết  tên  phi  công  được  phân  công  vào  ít  nhất  2  chuyến  bay  trong  cùng  một  ngày. 
select n.TEN
from PHANCONG p join LICHBAY l on (p.NGAYDI = l.NGAYDI and p.MACB = l.MACB)
	join NHANVIEN n on p.MANV = n.MANV
where n.LOAINV = 1
group by n.TEN, p.NGAYDI
having count(p.MACB) >= 2

--Cho  biết  mã  chuyến  bay  và  ngày  đi  của  những  chuyến  bay  có  ít  hơn  3  hành  khách  đặt 
--chỗ.
select l.MACB, l.NGAYDI
from LICHBAY l join DATCHO d on l.NGAYDI = d.NGAYDI and l.MACB = d.MACB
group by l.NGAYDI, l.MACB
having count(d.MAKH) < 3

--Cho  biết  số  hiệu  máy  bay  và  loại  máy  bay  mà  phi  công  có  mã  1001  được  phân  công  lái 
--trên  2  lần.
select l.MALOAI, l.SOHIEU
from PHANCONG p join LICHBAY l on p.NGAYDI = l.NGAYDI and p.MACB = l.MACB
where p.MANV = '1001'
group by l.MALOAI, l.SOHIEU
having count(*) > 2

--Với  mỗi  hãng  sản  xuất,  cho  biết  số  lượng  loại  máy  bay  mà  hãng  đó  đã  sản  xuất.  Xuất  ra 
--hãng  sản  xuất  và  số  lượng.
select HANGSX, count(*)
from LOAIMB
group by HANGSX

--Cho  biết  hãng  sản  xuất,  mã  loại  và  số  hiệu  của  máy  bay  đã  được  sử  dụng  nhiều  nhất.
select m.MALOAI, m.SOHIEU, l.HANGSX, count(*)
from maybay m join LOAIMB l on m.MALOAI = l.MALOAI
	join LICHBAY lb on m.MALOAI = lb.MALOAI and m.SOHIEU = lb.SOHIEU
group by m.MALOAI, m.SOHIEU, l.HANGSX
having count(*) >= all (
	select count(*)
	from maybay m2 join LOAIMB l2 on m2.MALOAI = l2.MALOAI
	join LICHBAY lb2 on m2.MALOAI = lb2.MALOAI and m2.SOHIEU = lb2.SOHIEU
	group by m2.MALOAI, m2.SOHIEU, l2.HANGSX
)

--Cho  biết  tên  nhân  viên  được  phân  công  đi  nhiều  chuyến  bay  nhất. 
select n.TEN
from PHANCONG p join NHANVIEN n on p.MANV = n.MANV
group by p.manv, n.TEN
having count(*) >= all (
	select count(*)
	from PHANCONG p2 join NHANVIEN n2 on p2.MANV = n2.MANV
	group by p2.manv, n2.TEN
)

--Cho  biết  sân  bay  (SBDEN)  và  số  lượng  chuyến  bay  của  sân  bay  có  ít  chuyến  bay  đáp 
--xuống  nhất. 
select c.SBDEN, count(*)
from chuyenbay c
group by c.SBDEN
having count(*)	>= all (
	select count(*)
	from CHUYENBAY c2
	group by c2.SBDEN
)

--Cho  biết  mã  số,  tên  và  lương  của  các  phi  công  có  khả  năng  lái  nhiều  loại  máy  bay  nhất.
select n.MANV, n.TEN, n.LUONG
from NHANVIEN n join KHANANG k on n.MANV = k.MANV
where n.LOAINV = 1
group by n.MANV, n.TEN, n.LUONG
having count(*) >= all (
	select count(*)
	from KHANANG k2
	group by k2.MANV
)

--Cho  biết  tên,  địa  chỉ  của  các  nhân  viên  có  lương  cao  nhất  trong  phi  hành  đoàn  (các 
--nhân  viên  được  phân  công  trong  một  chuyến  bay)  mà  người  đó  tham  gia.
select *
from NHANVIEN n join PHANCONG p on n.MANV = p.MANV
where n.LUONG >= all (
	select n2.LUONG 
	from NHANVIEN n2 join PHANCONG p2 on n2.MANV = p2.MANV
	where p.NGAYDI = p2.NGAYDI and p.MACB = p2.MACB
)

--Cho  biết  mã  chuyến  bay,  giờ  đi  và  giờ  đến  của  chuyến  bay  bay  sớm  nhất  trong  ngày. 
select *
from CHUYENBAY c
where c.GIODI <= all (
	select c2.GIODI
	from CHUYENBAY c2
)

--Với  mỗi  chuyến  bay  có  trên  3  hành  khách,  cho  biết  mã  chuyến  bay  và  số  lượng  nhân 
--viên  trên  chuyến  bay  đó.  Xuất  ra  mã  chuyến  bay  và  số  lượng  nhân  viên.
select l.MACB, count(distinct p.manv)
from LICHBAY l join DATCHO d on (l.NGAYDI = d.NGAYDI and l.MACB = d.MACB)
	join PHANCONG p on l.NGAYDI = p.NGAYDI and l.MACB = p.MACB
group by l.NGAYDI, l.MACB
having count(distinct d.MAKH) > 3