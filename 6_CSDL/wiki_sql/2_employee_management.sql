CREATE DATABASE Employee_management

GO

USE Employee_management

GO

CREATE TABLE Departments
(
	Code INT NOT NULL,
	Name VARCHAR(100),
	Budget DECIMAL(8,2),
	PRIMARY KEY(Code)
);

CREATE TABLE Employees
(
	SSN INT NOT NULL,
	Name VARCHAR(50),
	LastName VARCHAR(50),
	Department INT,
	PRIMARY KEY(SSN)
);

GO

INSERT INTO Departments(Code, Name, Budget) VALUES
	(14,'IT',65000),
	(37,'Accounting',15000),
	(59,'Human Resources',240000),
	(77,'Research',55000);

GO

INSERT INTO Employees(SSN,Name,LastName,Department) VALUES
	('123234877','Michael','Rogers',14),
	('152934485','Anand','Manikutty',14),
	('222364883','Carol','Smith',37),
	('326587417','Joe','Stevens',37),
	('332154719','Mary-Anne','Foster',14),
	('332569843','George','O''Donnell',77),
	('546523478','John','Doe',59),
	('631231482','David','Smith',77),
	('654873219','Zacary','Efron',59),
	('745685214','Eric','Goldsmith',59),
	('845657245','Elizabeth','Doe',14),
	('845657246','Kumar','Swamy',14);

GO

-- 1. Select the last name of all employees.
SELECT LastName
FROM Employees;

-- 2. Select the last name of all employees, without duplicates.
SELECT DISTINCT LastName
FROM Employees;

-- 3. Select all the data of employees whose last name is "Smith".
SELECT *
FROM Employees
WHERE LastName = 'Smith';

-- 4. Select all the data of employees whose last name is "Smith" or "Doe".
SELECT *
FROM Employees
WHERE LastName IN ('Smith', 'Doe');

-- 5. Select all the data of employees that work in department 14.
SELECT *
FROM Employees
WHERE Department = 14;

-- 6. Select all the data of employees that work in department 37 or department 77.
SELECT *
FROM Employees
WHERE Department IN (37, 77);

-- 7. Select all the data of employees whose last name begins with an "S".
SELECT *
FROM Employees
WHERE LastName like 'S%';

-- 8. Select the sum of all the departments' budgets.
SELECT SUM(Budget)
FROM Departments;

-- 9. Select the number of employees in each department
-- (you only need to show the department code and the number of employees).
SELECT Department, COUNT(*)
FROM Employees
GROUP BY Department;

-- 10. Select all the data of employees, including each employee's department's data.
SELECT *
FROM Employees e JOIN Departments d on e.Department = d.Code;

-- 11. Select the name and last name of each employee, along with the name and budget of the employee's department.
SELECT e.Name, e.LastName, d.Name, d.Budget
FROM Employees e JOIN Departments d on e.Department = d.Code;

-- 12. Select the name and last name of employees working for departments with a budget greater than $60,000.
SELECT e.Name, e.LastName
FROM Employees e JOIN Departments d on e.Department = d.Code
WHERE d.Budget > 60000;

-- 13. Select the departments with a budget larger than the average budget of all the departments.
-- AVG(BUFGET) must be in (SELECT)
SELECT *
FROM Departments
WHERE Budget > (SELECT AVG(BUDGET)
	FROM Departments);

-- 14. Select the names of departments with more than two employees.
SELECT d.Name
FROM Employees e JOIN Departments d on e.Department = d.Code
GROUP BY d.Name
HAVING COUNT(*) > 2;

SELECT Name
FROM Departments
WHERE Code in (SELECT Department
	FROM Employees
	GROUP BY Department
	HAVING COUNT(*) > 2);

-- 15. Select the name and last name of employees working for departments with second lowest budget.


-- 16. Add a new department called "Quality Assurance", with a budget of $40,000 and departmental code 11.
-- Add an employee called "Mary Moore" in that department, with SSN 847-21-9811.
INSERT INTO Departments(Name, Budget, Code) VALUES
	('Quality Assurance', 40000, 11);
GO
INSERT INTO Employees(Name, SSN, Department) VALUES
	('Mary Moore', '847219811', 11);

-- 17. Reduce the budget of all departments by 10%.
UPDATE Departments
	SET Budget = Budget - (Budget * 0.1);

-- 18. Reassign all employees from the Research department (code 77) to the IT department (code 14).
UPDATE Employees
	SET Department = 14
	WHERE Department = 77;

-- 19. Delete from the table all employees in the IT department (code 14).
DELETE FROM Employees
	WHERE Department = 14;

-- 20. Delete from the table all employees who work in departments with a budget greater than or equal to $60,000.
DELETE FROM Employees
	WHERE Department in (SELECT Code
						FROM Departments
						WHERE Budget >= 60000);

-- 21. Delete from the table all employees.
DELETE FROM Employees;

SELECT *
FROM Employees;