-- branch(branch name, branch city, assets)
-- customer (customer name, customer street, customer city)
-- loan (loan number, branch name, amount)
-- borrower (customer name, loan number)
-- account (account number, branch name, balance )
-- depositor (customer name, account number)

-- Find all customers who have an account at all the branches located in
-- "Brooklyn".
SELECT c.customer_name
FROM customer c
WHERE NOT EXISTT ((SELECT branch_name
		FROM branch
		WHERE branch_city = 'Brooklyn')
		except
		(SELECT branch_name
		FROM depositor d JOIN account a on d.customer_name = a.customer_name
		WHERE d.customer_name = c.customer_name))

-- Find out the total sum of all loan amounts in the bank
