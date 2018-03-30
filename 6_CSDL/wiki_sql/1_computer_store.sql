CREATE DATABASE COMPUTER_STORE;

GO

USE COMPUTER_STORE;

GO

CREATE TABLE Products
(
	Code INT NOT NULL,
	Name NVARCHAR(100),
	Price DECIMAL(5,1),
	Manufacture INT,
	PRIMARY KEY(Code)
);

CREATE TABLE Manufactures
(
	Code INT NOT NULL,
	Name NVARCHAR(100),
	PRIMARY KEY(Code)
);

GO

ALTER TABLE Products ADD
	CONSTRAINT FK_Products_Manufacture
	FOREIGN KEY(Manufacture) REFERENCES Manufactures(Code);

GO

INSERT INTO Manufactures(Code, Name) VALUES
	(1, N'Sony'),
	(2, N'Creative Labs'),
	(3, N'Hewlett-Packard'),
	(4, N'Iomega'),
	(5, N'Fujitsu'),
	(6, N'Winchester');

GO

INSERT INTO Products(Code, Name, Price, Manufacture) VALUES
	(1, N'Hard drive', 240, 5),
	(2, N'Memory', 120, 6),
	(3, N'ZIP drive', 150, 4),
	(4, N'Floppy disk', 5, 6),
	(5, N'Monitor', 240, 1),
	(6, N'DVD drive', 180, 2),
	(7, N'CD drive', 90, 2),
	(8, N'Printer', 270, 3),
	(9, N'Toner cartridge', 66, 3),
	(10, N'DVD burner', 180, 2);

-- 1. Select the names of all the products in the store.
SELECT Name
FROM Products;

-- 2. Select the names and the prices of all the products in the store.
SELECT Name, Price
FROM Products;

-- 3. Select the name of the products with a price less than or equal to $200.
SELECT Name
FROM Products
WHERE Price <= 200;

-- 4. Select all the products with a price between $60 and $120.
SELECT *
FROM Products
WHERE Price BETWEEN 60 AND 120;

-- 5. Select the name and price in cents (i.e., the price must be multiplied by 100).
SELECT Name, Price * 100 as 'Price in Cents'
FROM Products;

-- 6. Compute the average price of all the products.
SELECT AVG(Price) as AVG_Price
FROM Products;

-- 7. Compute the average price of all products with manufacturer code equal to 2.
SELECT AVG(Price) as AVG_Price
FROM Products
WHERE Manufacture = 2;

-- 8. Compute the number of products with a price larger than or equal to $180.
SELECT COUNT(*)
FROM Products
WHERE Price >= 180;


-- 9. Select the name and price of all products with a price larger than or equal to $180
-- and sort first by price (in descending order), and then by name (in ascending order).
SELECT Name, Price
FROM Products
WHERE Price >= 180
ORDER BY Price DESC, Name ASC;

-- 10. Select all the data from the products, including all the data for each product's manufacturer.
SELECT *
FROM Products p JOIN Manufactures m on p.Manufacture = m.Code;

-- 11. Select the product name, price, and manufacturer name of all the products.
SELECT p.Name, p.Price, m.Name
FROM Products p JOIN Manufactures m on p.Manufacture = m.Code;

-- 12. Select the average price of each manufacturer's products, showing only the manufacturer's code.
SELECT Manufacture, AVG(PRICE)
FROM Products
GROUP BY Manufacture;

-- 13. Select the average price of each manufacturer's products, showing the manufacturer's name.
SELECT m.Name, AVG(Price)
FROM Products p JOIN Manufactures m on p.Manufacture = m.Code
GROUP BY m.Name;

-- 14. Select the names of manufacturer whose products have an average price larger than or equal to $150.
SELECT m.Name
FROM Products p JOIN Manufactures m on p.Manufacture = m.Code
GROUP BY m.Name
HAVING AVG(Price) >= 150;

-- 15. Select the name and price of the cheapest product.
-- Find not cheapest -> some products more than some products
-- Minus not cheapest -> cheapest
SELECT ch.Name, ch.Price
FROM Products ch
WHERE ch.Code NOT IN(SELECT p.Code
	FROM Products p JOIN Products ap on p.Price > ap.Price);

SELECT Name, Price
FROM Products
WHERE Price = (SELECT MIN(Price)
	FROM Products);

-- 16. Select the name of each manufacturer along with the name and price of its most expensive product.
SELECT ex.Name, ex.Price
FROM Products ex
WHERE ex.Code NOT IN (SELECT p.Code
	FROM Products p JOIN Products cp on p.Price < cp.Price);

SELECT Name, Price
FROM Products
WHERE Price = (SELECT MAX(Price)
	FROM Products);

-- 17. Add a new product: Loudspeakers, $70, manufacturer 2.
INSERT INTO Products(Code, Name, Price, Manufacture) VALUES
	(11, N'Loudspeakers', 70, 2);

-- 18. Update the name of product 8 to "Laser Printer".
UPDATE Products
	SET Name = N'Laser Printer'
	WHERE Code = 8;

-- 19. Apply a 10% discount to all products.
UPDATE Products
	SET Price = Price * 0.9;

-- 20. Apply a 10% discount to all products with a price larger than or equal to $120.
UPDATE Products
	SET Price = Price * 0.9
	WHERE Price >= 120;

SELECT * FROM Products;