-- employee (employee name, street, city)
-- works (employee name, company name, salary)
-- company (company name, city)
-- manages (employee name, manager name)

-- Find the names and cities of residence of all employees who work for
-- "First Bank Corporation"
SELECT e.employee_name, e.city
FROM employee e JOIN works w on e.employee_name = w.employee_name
WHERE w.company_name = 'First Bank Corporation'

-- Find the names, street addresses, and cities of residence of all em-
-- ployees who work for “First Bank Corporation” and earn more than
-- $10,000
SELECT e.employee_name, e,street_address, e.city
FROM employee e JOIN works w on e.employee_name = w.employee_name
WHERE w.company_name = 'First Bank Corporation' AND w.salara > 10000

-- Find all employees in the database who do not work for "First Bank
-- Corporation"
SELECT e.employee_name
FROM employee e JOIN works w on e.employee_name = w.employee_name
WHERE w.company_name != 'First Bank Corporation'

-- Find all employees in the database who earn more than each employee
-- of "Small Bank Corporation"
SELECT employee_name
FROM works
WHERE salary > ALL(SELECT salary
		FROM works
		WHERE company_name = 'Small Bank Corporation')

-- Assume that the companies may be located in several cities. Find all
-- companies located in <<every>> city in which "Small Bank Corporation"
-- is located
SELECT c1.company_name
FROM company c1
WHERE NOT EXIST ((SELECT city
		FROM company
		WHERE company_name = 'Small Bank Corporation')
		EXCEPT
		(SELECT city
		WHERE company c2
		WHERE c2.city = c1.city))

-- Find the company that has the most employees
SELECT company_name
FROM works
GROUP BY company_name
HAVING count(employee_name) >= (SELECT count(employee_name)
				FROM works
				GROUP BY company_name)

-- Find those companies whose employees earn a higher salary, on av-
-- erage, than the average salary at "First Bank Corporation"
SELECT employee_name
FROM works
GROUP BY company
HAVING salary > (SELECT avg(salary)
		FROM works
		WHERE company_name = 'First Bank Corporation')