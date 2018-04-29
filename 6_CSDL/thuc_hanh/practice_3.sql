use QlyGV
GO

-- Xuất ra toàn bộ danh sách giáo viên.
create procedure sp_xuat_gv
as
	select *
	from giaovien

go
exec sp_xuat_gv

go
-- Tính số lượng đề tài mà một giáo viên đang thực hiện.
create procedure sp_dem_dt
	@magv char(3),
	@sl_dt int out
as
	select @sl_dt = count(t.magv)
	from giaovien g left join thamgiadt t on g.magv = t.magv
	where g.magv = @magv

go
declare @sl_dt int
exec sp_dem_dt '005', @sl_dt out
print @sl_dt

go
-- In thông tin chi tiết của một giáo viên(sử dụng lệnh print): Thông tin cá nhân, Số lượng đề tài
-- tham gia, Số lượng thân nhân của giáo viên đó.
create procedure sp_dem_ngthan
	@magv char(3),
	@sl_ngthan int out
as
	select @sl_ngthan = count(n.magv)
	from giaovien g left join nguoithan n on g.magv = n.magv
	where g.magv = @magv
go
alter procedure sp_thongtin_gv
	@magv char(3)
as
begin
	select *
	from giaovien
	where magv = @magv
	declare @sl_dt int
	exec sp_dem_dt @magv, @sl_dt out
	print 'So luong de tai tham gia: ' + cast(@sl_dt as VARCHAR)
	declare @sl_ngthan int
	exec sp_dem_ngthan @magv, @sl_ngthan out
	print 'So luong nguoi than: ' + cast(@sl_ngthan as VARCHAR)
end

go
exec sp_thongtin_gv '005'

go
-- Kiểm tra xem một giáo viên có tồn tại hay không (dựa vào MAGV).
create procedure sp_tontai_gv
	@magv char(3)
as
	if(
	exists(
	select *
	from giaovien
	where magv = @magv))
		print 'Ton tai'
	else
		print 'Khong ton tai'

go
exec sp_tontai_gv '010'

-- Thực hiện xoá một giáo viên theo mã. Nếu giáo viên có thông tin liên quan (Có thân nhân, có
-- làm đề tài, ...) thì báo lỗi.
go
create procedure sp_xoa_gv 
	@magv char(3)
as
begin
	declare @hop_le int
	set @hop_le = 1
	
	-- co tham gia dt
	if(@magv in (
	select magv
	from thamgiadt))
		set @hop_le = 0
	
	-- co nguoi than
	if(@magv in (
	select magv
	from nguoithan))
		set @hop_le = 0
	
	-- co quan ly gv khac
	if(@magv in(
	select gvqlcm
	from giaovien))
		set @hop_le = 0
	
	-- lam truong bo mon
	if(@magv in (
	select truongbm
	from bomon))
		set @hop_le = 0
	
	-- lam truong khoa
	if(@magv in (
	select truongkhoa 
	from khoa))
		set @hop_le = 0
	
	-- lam chu nhiem de tai
	if(@magv in (
	select gvcndt
	from detai))
		set @hop_le = 0

	if(@hop_le = 1)
	begin
		delete from giaovien
		where magv = @magv
		print 'Xoa thanh cong'
	end
	else
		print 'Khong the xoa'
end
