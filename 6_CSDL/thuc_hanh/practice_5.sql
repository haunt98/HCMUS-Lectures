use test_procedure_func
go
create function f_tuoi (@ngsinh date)
returns int
as
begin
	return datediff(yy, @ngsinh, getdate())
end
go
print dbo.f_tuoi('03-28-1998')

go
use QlyGV
go
create function f_ds_bomon (@bomon nchar(4))
returns table
as
	return(
	select g.*
	from giaovien g right join bomon b on g.mabm = b.mabm
	where b.mabm = @bomon  
	)

go
select *
from dbo.f_ds_bomon('CNTT')