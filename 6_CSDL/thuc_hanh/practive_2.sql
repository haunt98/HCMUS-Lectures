create database qltv
go
use qltv
go

create table docgia
(
	ma_doc_gia int,
	ho nchar(100),
	tenlot nchar(100),
	ten nchar(100),
	ngaysinh date,
	primary key(ma_doc_gia)
);

create table nguoilon
(
	ma_doc_gia int,
	sonha nchar(100),
	duong nchar(100),
	
);