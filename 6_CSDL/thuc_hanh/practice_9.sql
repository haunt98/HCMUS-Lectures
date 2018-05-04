--Create Demo Database
CREATE DATABASE SqlHintsLogicalTablesDemo
GO
USE SqlHintsLogicalTablesDemo
GO
--Create Customer Table
CREATE TABLE Customer 
( CustomerId INT IDENTITY (1, 1) NOT NULL ,
  FirstName NVARCHAR(50), LastName NVARCHAR(50))
GO
--Add sample records
INSERT INTO dbo.Customer ( FirstName, LastName )
VALUES('Basavaraj','Biradar'),
      ('Kalpana','Patil')

go
alter TRIGGER INSERTEDAndDELETEDTableExample
ON Customer
for INSERT, UPDATE, DELETE
AS
BEGIN
	 print '**OLD table**'
	 select * from Customer
     PRINT '**********DELETED Table***************'
     SELECT * FROM DELETED
     PRINT '*********INSERTED Table***************'
     SELECT * FROM INSERTED
END

go

INSERT INTO dbo.Customer ( FirstName, LastName )
VALUES('Shreeganesh','Biradar')

DELETE FROM Customer WHERE CustomerId = 2


UPDATE Customer
SET FirstName = 'Mr. ' + FirstName
