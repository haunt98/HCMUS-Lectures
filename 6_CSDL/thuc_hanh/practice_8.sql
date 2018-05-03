use QuanLyDeTai
go

create trigger trg_luong
on giaovien
for insert, update
as
if update(luong)
begin
	if(exists(
	select *
	from inserted i
	where i.luong < 1000))
	begin
		raiserror('Luong giao vien phai >= 1000', 16, 1)
		rollback
	end
end

go
insert into giaovien(MAGV, luong) values
	('099', 800);

go

create trigger trig_trbm
on bomon
for update 
as
if update(truongbm)
begin
	if(exists(
	select *
	from inserted i join giaovien g on i.truongbm = g.magv
	where i.mabm is null or i.mabm != g.mabm))
	begin
		raiserror('Truong bo mon phai la nguoi trong bo mon',16,1) 
		rollback
	end
end

go
create trigger trig_gv
on giaovien
for update
as
if update(mabm)
begin
	if(exists(
	select *
	from inserted i join bomon b on i.magv = b.truongbm
	where i.mabm is null or i.mabm != b.mabm))
	begin
		raiserror('Giao vien la truong bo mon khong duoc thay doi bo mon', 16, 1)
		rollback
	end
end

update giaovien
set mabm = null
where magv = '002'

go

-- Một bộ môn có tối thiểu 1 giáo viên nữ
alter trigger trig_toithieu_1nu
on giaovien
for delete, update
as
begin
	declare @flag int
	set @flag = 1
	if update(phai)
	begin
		if(not exists(
		select *
		from deleted d join giaovien g on d.mabm = g.mabm
		where g.phai = N'Nữ'))
		begin
			set @flag = 0
		end
	end
end

select *
from giaovien 

update giaovien
set phai = N'Nam'
where magv = '006' 

insert into giaovien(magv, mabm, phai) values
	('099', N'VLĐT', N'Nữ')

delete from giaovien
-- set mabm = 'HTTT'
where magv = '099'

-- Tên đề tài phải duy nhất
--		T	X	S
--	DT	+	-	+(TenDT)
go
create trigger trig_ten_dt_duynhat
on detai
for insert, update
as
	if(update(tendt))
	begin
		if(exists(
		select *
		from detai d 
		where d.TENDT in (
			select i.tendt
			from inserted i
			where i.madt != d.madt)))
		begin
			raiserror('Ten de tai phai la duy nhat',16,1)
			rollback
		end
	end

select *
from detai

update detai
set tendt = N'Ứng dụng hóa học xanh'
where madt = '002'

insert into detai(madt, tendt) values
	('099', N'HTTT quản lý các trường ĐH');

-- Trưởng bộ môn phải sinh trước 1975
--		T	X	S
-- GV	-	-	+(ngsinh)	
-- BM	+	-	+(truongbm)
go
create trigger trig_gv_sinh_1975
on giaovien
for update
as
	if(update(ngsinh))
	begin
		if(exists(
		select *
		from inserted i
		where year(i.ngsinh) >= 1975 and i.magv in (
			select truongbm
			from bomon)))
		begin
			raiserror('Truong bo mon khong the sinh sau 1975',16,1)
			rollback
		end
	end
go
create trigger trig_bm_sinh_1975
on bomon
for insert, update
as
	if (update(truongbm))
	begin
		if(exists(
		select *
		from giaovien
		where year(ngsinh)>=1975 and magv in (
			select truongbm
			from inserted)))
		begin
			raiserror('Truong bo mon khong the sinh sau 1975',16,1)
			rollback
		end
	end
go
select *
from giaovien
where magv in (
	select truongbm
	from bomon)

select *
from bomon

update giaovien
set ngsinh = '1988-01-01'
where magv = '001'

update bomon
set truongbm = '006'
where mabm = N'VS'

-- Một giáo viên phải có ít nhất 1 số điện thoại
--		T	X	S
-- gv	+	-	+(magv)
-- dt	-	+	+(magv)
go
create trigger trig_gv_1_dt
on giaovien
for insert, update
as
	if(update(magv))
	begin
		if(not exists(
		select *
		from gv_dt
		where magv in (
			select magv
			from inserted)))
		begin
			raiserror('Mot giao vien phai co it nhat 1 sdt',16,1)
			rollback
		end
	end
go
create trigger trig_gv_dt_1_dt
on gv_dt
for delete, update
as
	begin
		if(not exists(
		select *
		from gv_dt
		where magv in (
			select magv
			from deleted)))
			begin
				raiserror('Mot giao vien phai co it nhat 1 so dien thoai', 16, 1)
				rollback
			end
	end
go
select *
from giaovien
where magv not in(
	select magv
	from gv_dt)

insert into gv_dt(magv, dienthoai) values
	('004', '004'),
	('005', '005'),
	('007', '007'),
	('009', '009'),
	('010', '010');

select * 
from gv_dt

insert into giaovien(magv) values
	('099')

delete from gv_dt
where magv = '004'

-- Một giáo viên có tối đa 3 số điện thoại
--		T	X	S
-- gv	-	-	+(magv)
-- dt	+	-	+(magv)
go
create trigger trig_gv_3_dt
on giaovien
for update
as
	if(update(magv))
	begin
		if(3<(
		select count(*)
		from gv_dt
		where magv in (
			select magv
			from inserted)))
		begin
			raiserror('Mot giao vien chi toi da 3 sdt',16,1)
			rollback
		end
	end
go

create trigger trig_gv_dt_3_dt
on gv_dt
for insert, update
as
	if(update(magv))
	begin
		if(3 <(
		select count(*)
		from gv_dt
		where magv in (
			select magv
			from inserted)))
		begin
			raiserror('Mot giao vien chi toi da 3 sdt',16,1)
			rollback
		end
	end

select *
from gv_dt
where magv = '003'

delete from gv_dt
where magv = '003' and dienthoai = '0838121212'

delete from gv_dt
where magv = '001' and dienthoai = '001'

insert into gv_dt(magv, dienthoai) values
	('001', '001')

-- Trưởng bộ môn phải là người lớn tuổi nhất trong bộ môn.
--		t	x	s
-- gv	-	-	+(ngsinh)
-- bm	+	-	+(truongbm)
go
alter trigger trig_gv_trbm_lontuoi
on giaovien
for update
as
	if(update(ngsinh))
	begin
		if(not exists(
		select *
		from giaovien g join bomon b on g.magv = b.truongbm
		where b.mabm in (
			select mabm
			from inserted)
		and year(g.ngsinh) <= all (
			select year(g2.ngsinh)
			from giaovien g2
			where g2.mabm = b.mabm)))
		begin
			raiserror('Truong bo mon phai lon tuoi nhat',16,1)
			rollback
		end
	end
go
create trigger trig_bm_trbm_lontuoi
on bomon
for insert, update
as
	if(update(truongbm))
	begin
	if(not exists(
	select *
	from giaovien g1
	where g1.magv in (
		select truongbm
		from inserted)
	and year(ngsinh) <= all(
		select year(ngsinh)
		from giaovien g2
		where g2.mabm = g1.mabm and g2.magv != g1.magv)))
	begin
		raiserror('Truong bo mon phai gia` nhat',16,1)
		rollback
	end
	end

go
update giaovien
set ngsinh = '1970-01-01'
where magv = '006' 

select *
from giaovien
where mabm = 'httt'
select * 
from bomon
where mabm = 'httt'

update giaovien
set ngsinh = '1970-01-01'
where magv = '003'

update bomon
set truongbm = '003'
where mabm = 'httt'