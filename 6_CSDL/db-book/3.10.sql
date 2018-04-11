# employee (employee name, street, city)
# works (employee name, company name, salary)
# company (company name, city)
# manages (employee name, manager name)

# Modify the database so that “Jones” now lives in “Newtown”.
UPDATE employee
	SET city = 'Newtown'
	WHERE employee_name = 'Jones'

# Give all managers of “First Bank Corporation” a 10 percent raise
# unless the salary becomes greater than $100,000; in such cases, give
# only a 3 percent raise.
UPDATE works w
	SET salary = salary * (
		case
			when (salary * 1.1 > 100000) then 1.03
			else 1.1
		)
	WHERE employee_name in (SELECT manager_name
				FROM managers) AND w.company_name = 'First Bank Corporation')