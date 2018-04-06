# person (driver id, name, address) 1
# car (license, model, year) 1
# accident (report number, date, location) 1
# owns (driver id, license) 2
# participated (report number, license, driver id, damage amount) 2

# Find the total number of people who owned cars that were involved
# in accidents in 2009
SELECT count(DISTINCT p.driver_id)
FROM accident a JOIN participated p on a.report_number = p.report_number
WHERE YEAR(date) = 2009

# Add a new accident to the database; assume any values for required
# attributes.
INSERT INTO accident(report_number, date, location) VALUES
	('X', '1990-02-27', 'New York')

# Delete the Mazda belonging to "John Smith"
DELETE FROM car
	WHERE model = 'Mazda' AND license IN (SELECT c.license
		FROM (car c JOIN owns o ON c.license = o.license)
			JOIN person p on p.driver_id = o.driver_id
		WHERE p.name = 'John Smith')