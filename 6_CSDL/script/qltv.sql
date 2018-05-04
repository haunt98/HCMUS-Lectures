create database qltv
go
use qltv
go

create table docgia (
	ma_docgia int,
	ho nvarchar(50),
	tenlot nvarchar(50),
	ten nvarchar(50),
	ngaysinh date,
	primary key(ma_docgia)
)

create table treem (
	ma_docgia int,
	ma_docgia_nguoilon int,
	primary key(ma_docgia)
)

create table nguoilon (
	ma_docgia int,
	sonha int,
	duong nvarchar(50),
	quan nvarchar(50),
	dienthoai nvarchar(50),
	han_sd date,
	primary key(ma_docgia)
)

create table tuasach (
	ma_tuasach int,
	tuasach nvarchar(50),
	tacgia nvarchar(50),
	tomtat ntext,
	primary key(ma_tuasach)
)

create table dausach (
	isbn int,
	ma_tuasach int,
	ngonngu nvarchar(50),
	bia nvarchar(50),
	trang_thai char(1),
	primary key(isbn)
)

create table cuonsach (
	isbn int,
	ma_cuonsach int,
	tinhtrang char(1),
	primary key (isbn, ma_cuonsach),
)

create table muon (
	isbn int,
	ma_cuonsach int,
	ma_docgia int,
	ngaygio_muon datetime,
	ngay_hethan datetime,
	primary key (isbn, ma_cuonsach),
)

create table dangky (
	isbn int,
	ma_docgia int,
	ngaygio_dk datetime,
	ghichu ntext,
	primary key (isbn, ma_docgia),
)

create table quatrinhmuon (
	isbn int,
	ma_cuonsach int,
	ngaygio_muon datetime,
	ma_docgia int,
	ngay_hethan datetime,
	ngaygio_tra datetime,
	tien_muon money,
	tien_datra money,
	tien_datcoc money,
	ghichu ntext,
	primary key (isbn, ma_cuonsach, ngaygio_muon),
)
go

alter table treem add 
	constraint fk_treem_mdgnl
	foreign key (ma_docgia_nguoilon) references nguoilon(ma_docgia)
alter table dausach add 
	constraint fk_dausach_mts
	foreign key (ma_tuasach) references tuasach(ma_tuasach)
alter table dangky add 
	constraint fk_dangky_mdg
	foreign key (ma_docgia) references docgia(ma_docgia),
	constraint fk_dangky_isbn
	foreign key (isbn) references dausach(isbn)
alter table muon add 
	constraint fk_muon_isbnmcs
	foreign key (isbn, ma_cuonsach) references cuonsach(isbn, ma_cuonsach),
	constraint fk_muon_mdg
	foreign key (ma_docgia) references docgia(ma_docgia)

alter table cuonsach add 
	constraint fk_cuonsach_isbn
	foreign key (isbn) references dausach(isbn)

alter table quatrinhmuon add 
	constraint fk_quatrinhmuon_isbnmcs
	foreign key (isbn, ma_cuonsach) references cuonsach(isbn, ma_cuonsach),
	constraint fk_quatrinhmuon_mdg
	foreign key (ma_docgia) references docgia(ma_docgia)
go
