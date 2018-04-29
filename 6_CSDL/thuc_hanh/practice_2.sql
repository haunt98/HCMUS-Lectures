create database test_procedure_func
go
use test_procedure_func
go

-- 1/ Hello
create procedure sp_hello
as
	declare @msg nvarchar(1000)
	set @msg = N'Hello World'
	select @msg;

exec sp_hello;

-- 2/ Tong 2 so
create procedure sp_tong
	@num1 int,
	@num2 int
as
	declare @sum int
	set @sum = @num1 + @num2
	select @sum

exec sp_tong 1,2;

-- 3/ Tong cac so chan trong [m, n]
create procedure sp_tong_chan
	@m int,
	@n int
as
	declare @sum int, @i int
	set @sum = 0
	set @i = @m
	while (@i <= @n)
	begin
		if(@i % 2 = 0)
		begin
			set @sum = @sum + @i
		end
		set @i = @i + 1
	end
	select @sum

exec sp_tong_chan 5, 12;

-- 4/ Kiem tra su ton tai cua giao vien theo magv
use QlyGV
alter procedure sp_tontai_gv 
	@magv char(3)
as
	if(exists(
	select *
	from giaovien
	where magv = @magv))
		print 'Ton tai';
	else
		print 'Khong ton tai';

exec sp_tontai_gv '011'

-- 5/ Xuat danh sach giao vien theo mabm
create procedure sp_xuat_bomon 
	@mabm nchar(4)
as
	select *
	from giaovien
	where mabm = @mabm;

exec sp_xuat_bomon N'HTTT'

-- 6/ Tong 2 so co output
use test_procedure_func
create procedure tong_out
	@num1 int,
	@num2 int,
	@sum int out
as
	set @sum = @num1 + @num2

declare @sum_2 int
exec tong_out 1, 15, @sum_2 out
print @sum_2

-- 7/ Tong 3 so, su dung lai 6/
alter procedure tong_3_out
	@num1 int,
	@num2 int,
	@num3 int,
	@sum int out
as
	declare @temp int
	exec tong_out @num1, @num2, @temp out
	exec tong_out @temp, @num3, @sum out

declare @sum_3 int
exec tong_3_out 1, 2, 3, @sum_3 out
print @sum_3

-- 8/ Tong 4 so, su dung 6/
create procedure tong_4_out
	@num1 int,
	@num2 int,
	@num3 int,
	@num4 int,
	@sum int out
as
	declare @temp1 int, @temp2 int
	exec tong_out @num1, @num2, @temp1 out
	exec tong_out @num3, @num4, @temp2 out
	exec tong_out @temp1, @temp2, @sum out

declare @tong_4 int
exec tong_4_out 1, 2, 3, 4, @tong_4 out
print @tong_4

-- 9/ Kiem tra so nguyen to
create procedure sp_is_prime
	@n int
as
	declare @la_nguyen_to int
	set @la_nguyen_to = 1
	if(@n < 2)
		set @la_nguyen_to = 0
	else
	begin
		if(@n = 2)
			set @la_nguyen_to = 1
		else
		begin
			if(@n % 2 = 0)
				set @la_nguyen_to = 0
			else
			begin
			declare @i int
			set @i = 3
			while (@i * @i <= @n)
			begin
				if(@n % @i =0)
				begin
					set @la_nguyen_to = 0
					break
				end
				set @i = @i + 2
			end
			end
		end
	end	

	if(@la_nguyen_to = 1)
		print 'Nguyen to'
	else
		print 'Khong phai nguyen to'

exec sp_is_prime 9

-- 10/ Tim UCLN
alter procedure sp_ucln
	@a int,
	@b int,
	@ucln int out
as
begin
	declare @a_pos int, @b_pos int
	if (@a < 0)
		set @a_pos = -@a
	else 
		set @a_pos = @a
	if (@b < 0)
		set @b_pos = -@b
	else 
		set @b_pos = @b
	while (@a_pos != 0 and @b_pos !=0)
	begin
		if(@a_pos > @b_pos)
			set @a_pos = @a_pos % @b_pos
		else
			set @b_pos = @b_pos % @a_pos
	end
	if (@a_pos = 0 and @b_pos = 0)
		set @ucln = 1
	else
	begin
		if (@a_pos = 0)
			set @ucln = @b_pos
		else
			set @ucln = @a_pos
	end
end

declare @ucln_t int
exec sp_ucln 15, 15, @ucln_t out
print @ucln_t

-- 11/ Tim BCNN
create procedure sp_bcnn
	@a int,
	@b int,
	@bcnn int out
as
	declare @a_pos int, @b_pos int
	if (@a < 0)
		set @a_pos = -@a
	else 
		set @a_pos = @a
	if (@b < 0)
		set @b_pos = -@b
	else 
		set @b_pos = @b
	declare @ucln_b int
	exec sp_ucln @a_pos, @b_pos, @ucln_b out
	set @bcnn = @a_pos * @b_pos / @ucln_b

declare @bcnn_t int
exec sp_bcnn 5,15, @bcnn_t out
print @bcnn_t