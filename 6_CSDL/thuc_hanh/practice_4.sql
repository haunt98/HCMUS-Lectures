create database db_phong
go
use database db_phong
go
create table phong
(
	maphong int not null,
	tinhtrang nchar(4),
	loaiphong char(1),
	dongia numeric(8,2),
	primary key(maphong)	
)

create table khach
(
	makh int not null,
	hoten nvarchar(100),
	diachi nvarchar(100),
	dienthoai char(11),
	primary key(makh)
)

create table datphong
(
	ma int not null,
	makh int,
	maphong int,
	ngaydat date,
	ngaytra date, 
	thanhtien numeric(8,2)
	primary key(ma)
)
go

alter table datphong add
	constraint fk_datphong_makh
	foreign key(makh) references khach(makh),
	constraint fk_datphong_maphong
	foreign key(maphong) references phong(maphong)

go

insert into khach(makh) values
	(1),
	(2),
	(3);

insert into phong(maphong, tinhtrang, dongia) values
	(1, N'Rảnh', 1000),
	(2, N'Bận', 1500),
	(3, N'Rảnh', 1000);

go
create procedure spDatPhong
	@makh int,
	@maphong int,
	@ngaydat date
as
begin
	declare @hop_le int
	set @hop_le = 1
	-- khong ton tai khach hang
	if(@makh not in 
	(select makh
	from khach))
	begin
		set @hop_le = 0
		print 'Khong ton tai khach hang'
	end
	-- khong ton tai phong ranh
	if(not exists(
	select *
	from phong
	where maphong = @maphong and tinhtrang = N'Rảnh'))
	begin
		set @hop_le = 0
		print 'Khong ton tai phong ranh'
	end
	if(@hop_le = 1)
	begin
		-- tim ma lon nhat trong datphong
		declare @ma int
		select @ma = isnull (max(ma), 0) + 1
		from datphong
		insert into datphong(ma, makh, maphong, ngaydat) values
			(@ma, @makh, @maphong, @ngaydat)
		update phong
			set tinhtrang = N'Bận'
			where maphong = @maphong
		print 'Them thanh cong'
	end
	else
		print 'Them that bai'
end
go
delete from datphong
update phong
	set tinhtrang = N'Rảnh'
select * from phong
select * from khach
select * from datphong
exec spDatPhong 1, 1, '03-20-2018'
exec spDatPhong 2, 3, '03-20-2018'

go
create procedure spTraPhong
	@madp int,
	@makh int
as
begin
	declare @hop_le int
	set @hop_le = 1
	-- kiem tra hop le
	if(not exists(
	select *
	from datphong
	where ma = @madp and makh = @makh))
	begin
		print 'Khong ton tai ma phong va ma khach hang trong dat phong'
		set @hop_le = 0
	end
	-- thuc hien tra
	if(@hop_le = 1)
	begin
		-- lay don gia va ma phong sap tra
		declare @dongia numeric(8, 2), @maphong int
		select @dongia = p.dongia, @maphong = p.maphong
		from phong p join datphong d on p.maphong = d.maphong
		where d.ma = @madp
		print @dongia
		-- tra phong
		update datphong 
		set	ngaytra = getdate(), thanhtien = datediff(d, ngaydat, getdate()) * @dongia
		where ma = @madp
		-- cap nhap phong ranh
		update phong 
		set tinhtrang = N'Rảnh'
		where maphong = @maphong
		print 'Tra thanh cong'
	end
	else
		print 'Tra that bai'
end
go
select * from phong
select * from khach
select * from datphong
exec spTraPhong 2, 2