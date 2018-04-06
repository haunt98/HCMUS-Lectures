# branch (branch name, branch city, assets) 1
# customer (customer name, customer street, customer city) 1
# loan (loan number, branch name, amount) 1
# borrower (customer name, loan number) 2
# account (account number, branch name, balance ) 1
# depositor (customer name, account number) 1

# Find all customers of the bank who have an account but not a loan
(SELECT customer_name
FROM depositor)
EXCEPT
(SELECT customer_name
FROM borrower)

SELECT
FROM borrower b RIGHT JOIN depositor d on b.customer_name = d.customer_name
WHERE b.loan_number IS NULL

# Find the names of all customers who live on the same street and in
# the same city as "Smith"
SELECT ns.customer_name
FROM customer s JOIN customer ns ON (s.customer_street = ns.customer_street AND s.customer_city = ns.customer_city)
WHERE s.customer_name = 'Smith'

# Find the names of all branches with customers who have an account
# in the bank and who live in "Harrison"
SELECT DISTINCT a.branch_name
FROM (account a JOIN depositor d ON a.account_number = d.account_number)
	JOIN customer c on d.customer_name = c.customer_name
WHERE c.customer_street = 'Harrison'