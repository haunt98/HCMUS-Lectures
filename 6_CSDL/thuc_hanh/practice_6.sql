use test_procedure_func
go
-- Viet ham tinh so tien khi giao dich tai khoan
-- so tien < 10 kq = sotien + 4
-- so tien > 10
-- Vang: kq = sotien * 1.05
-- Bac, dong la 1.1 va 1.2
alter function f_tinhtien(@sotien float, @loaitk nchar(4))
returns float
as
begin
	if(@sotien < 10)
		return @sotien + 4
	else
	begin
		if(@loaitk = N'Vàng')
			return @sotien * 1.05
		if(@loaitk = N'Bạc')
			return @sotien * 1.1
		if(@loaitk = N'Đồng')
			return @sotien * 1.2
	end
	return @sotien + 4
end

go
print dbo.f_tinhtien(12, N'Vàng')

go
create table taikhoan 
(
	sotk char(1) not null,
	tentk nvarchar(100),
	sodu float,
	loaitk nchar(4)
	primary key(sotk)
) 

go
insert into taikhoan(sotk, loaitk) values	
	('A', N'Vàng'),
	('B', N'Bạc'),
	('C', N'Đồng');

go