CREATE DATABASE The_warehouse;

GO

USE The_warehouse;

GO

CREATE TABLE Warehouses
(
	Code INT NOT NULL,
	Location VARCHAR(100),
	Capacity INT,
	PRIMARY KEY(CODE)
);

CREATE TABLE Boxes
(
	Code CHAR(4) NOT NULL,
	Contents VARCHAR(100),
	Value REAL,
	Warehouse INT,
	PRIMARY KEY(Code)
);

GO

ALTER TABLE Boxes ADD
	CONSTRAINT FK_Boxes_Warehouse
	FOREIGN KEY(Warehouse) REFERENCES Warehouses(Code);

GO

INSERT INTO Warehouses(Code,Location,Capacity) VALUES(1,'Chicago',3);
INSERT INTO Warehouses(Code,Location,Capacity) VALUES(2,'Chicago',4);
INSERT INTO Warehouses(Code,Location,Capacity) VALUES(3,'New York',7);
INSERT INTO Warehouses(Code,Location,Capacity) VALUES(4,'Los Angeles',2);
INSERT INTO Warehouses(Code,Location,Capacity) VALUES(5,'San Francisco',8);

GO

INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('0MN7','Rocks',180,3);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('4H8P','Rocks',250,1);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('4RT3','Scissors',190,4);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('7G3H','Rocks',200,1);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('8JN6','Papers',75,1);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('8Y6U','Papers',50,3);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('9J6F','Papers',175,2);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('LL08','Rocks',140,4);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('P0H6','Scissors',125,1);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('P2T6','Scissors',150,2);
INSERT INTO Boxes(Code,Contents,Value,Warehouse) VALUES('TU55','Papers',90,5);

GO

-- 1. Select all warehouses.
SELECT *
FROM Warehouses;

-- 2. Select all boxes with a value larger than $150.
SELECT *
FROM Boxes
WHERE Value > 150;

-- 3. Select all distinct contents in all the boxes.
SELECT DISTINCT Contents
FROM Boxes;

-- 4. Select the average value of all the boxes.
SELECT AVG(Value)
FROM Boxes;

-- 5. Select the warehouse code and the average value of the boxes in each warehouse.
SELECT Warehouse, AVG(Value)
FROM Boxes
GROUP BY Warehouse;

-- 6. Same as previous exercise, but select only those warehouses where the average value of the boxes is greater than 150.
SELECT Warehouse
FROM Boxes
GROUP BY Warehouse
HAVING AVG(Value) > 150;

-- 7. Select the code of each box, along with the name of the city the box is located in.
SELECT b.Code, w.Location
FROM Boxes b JOIN Warehouses w on b.Warehouse = w.Code;

-- 8. Select the warehouse codes, along with the number of boxes in each warehouse.
-- Optionally, take into account that some warehouses are empty
-- (i.e., the box count should show up as zero, instead of omitting the warehouse from the result).
SELECT w.Code, COUNT(*)
FROM Warehouses w LEFT JOIN Boxes b on w.Code = b.Warehouse
GROUP BY w.Code;

-- 9. Select the codes of all warehouses that are saturated
-- (a warehouse is saturated if the number of boxes in it is larger than the warehouse's capacity).
SELECT w.Code
FROM Warehouses w
WHERE w.Capacity <= (SELECT COUNT(*)
	FROM Boxes b
	WHERE b.Warehouse = w.Code);

-- 10. Select the codes of all the boxes located in Chicago.
SELECT b.Code
FROM Boxes b JOIN Warehouses w on b.Warehouse = w.Code
WHERE w.Location = 'Chicago';

-- 11. Create a new warehouse in New York with a capacity for 3 boxes.
INSERT INTO Warehouses(Code, Capacity, Location) VALUES
	(6, 3, 'New York');

-- 12. Create a new box, with code "H5RT", containing "Papers" with a value of $200, and located in warehouse 2.
INSERT INTO Boxes(Code, Contents, Value, Warehouse) VALUES
	('H5RT', 'Papers', 200, 2);

-- 13. Reduce the value of all boxes by 15%.
UPDATE  Boxes
	SET Value = Value - (Value * 0.15);

-- 14. Apply a 20% value reduction to boxes with a value larger than the average value of all the boxes.
UPDATE Boxes
	SET Value = Value - (Value * 0.2)
	WHERE Value > (SELECT AVG(Value)
		FROM Boxes);

-- 15. Remove all boxes with a value lower than $100.
DELETE FROM Boxes
	WHERE Value < 100;

-- 16. Remove all boxes from saturated warehouses.
-- Find all boxes in Warehouses which saturated
DELETE FROM Boxes
	WHERE Warehouse IN (SELECT w.Code
					FROM Warehouses w
					WHERE w.Capacity <= (SELECT COUNT (*)
									FROM Boxes b
									WHERE b.Warehouse = w.Code));
