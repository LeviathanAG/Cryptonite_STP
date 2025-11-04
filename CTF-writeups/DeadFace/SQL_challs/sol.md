# all the sql commands to get the flags

```bash
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{', COUNT(*), '}') AS flag
FROM customers
WHERE join_date >= '2025-09-01';
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+----------------------------+
| flag                       |
+----------------------------+
| 0x64656164666163657B31387D |
+----------------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{', p.product_name, '}') AS flag
FROM products p
JOIN reviews r ON p.product_id = r.product_id
GROUP BY p.product_id, p.product_name
ORDER BY AVG(r.rating) DESC
LIMIT 1;
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+-----------------------------+
| flag                        |
+-----------------------------+
| deadface{VortexAudio Focus} |
+-----------------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{', p.product_name, ' ', i.facility_num, '}') AS flag
FROM inventories i
JOIN products p ON i.product_id = p.product_id
WHERE i.quantity < 5
ORDER BY i.quantity ASC
LIMIT 1;
"
mysql: [Warning] Using a password on the command line interface can be insecure.
ERROR 1054 (42S22) at line 2: Unknown column 'i.facility_num' in 'field list'
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' -e "
SELECT column_name, data_type
FROM information_schema.columns
WHERE table_schema='epicsales_db' AND table_name='inventories';
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------+-----------+
| column_name  | data_type |
+--------------+-----------+
| inventory_id | int       |
| product_id   | int       |
| facility_id  | int       |
| quantity     | int       |
+--------------+-----------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{', p.product_name, ' ', i.facility_id, '}') AS flag
FROM inventories i
JOIN products p ON i.product_id = p.product_id
WHERE i.quantity < 5
ORDER BY i.quantity ASC
LIMIT 1;
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+----------------------------------------+
| flag                                   |
+----------------------------------------+
| deadface{ConnectGear SafeDrive 2TB 16} |
+----------------------------------------+
(base) ss@Satwik:~$ mongod
^C(base) ss@Satwik:~$ mongo
Command 'mongo' not found, did you mean:
  command 'mono' from deb mono-runtime (6.8.0.105+dfsg-3.5ubuntu1)
Try: sudo apt install <deb name>
(base) ss@Satwik:~$ GET http://localhost:8006/hotels/v3/get-all-hotels?cityCode=130443
Can't connect to localhost:8006 (Connection refused)

Connection refused at /usr/share/perl5/LWP/Protocol/http.pm line 49.
(base) ss@Satwik:~$ curl GET http://localhost:8006/hotels/v3/get-all-hotels?cityCode=130443
curl: (6) Could not resolve host: GET
curl: (7) Failed to connect to localhost port 8006 after 9 ms: Couldn't connect to server
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', FORMAT(SUM(pay_rate), 2), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+---------------------+
| flag                |
+---------------------+
| deadface{$7,391.20} |
+---------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate), 2), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------------+
| flag               |
+--------------------+
| deadface{$7391.20} |
+--------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT DISTINCT role FROM employees;
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+---------------------------------+
| role                            |
+---------------------------------+
| Accountant                      |
| Packer                          |
| Inventory Specialist            |
| Accounting Clerk                |
| CTO                             |
| Recruiter                       |
| Software Developer              |
| Order Picker                    |
| Product Manager                 |
| IT Support Specialist           |
| Marketing Coordinator           |
| Warehouse Clerk                 |
| Network Administrator           |
| Finance Manager                 |
| Quality Control Inspector       |
| Customer Service Representative |
| Operations Director             |
| Accounts Payable Specialist     |
| Receiving Clerk                 |
| Customer Support Specialist     |
| HR Specialist                   |
| Warehouse Supervisor            |
| Data Analyst                    |
| Accounts Receivable Specialist  |
| Shipping Coordinator            |
| Budget Analyst                  |
| Warehouse Manager               |
| Maintenance Technician          |
| Forklift Operator               |
| IT Manager                      |
| Financial Analyst               |
| Payroll Administrator           |
| HR Manager                      |
| Customer Relations Manager      |
| Sales Manager                   |
| CEO                             |
| CFO                             |
+---------------------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' -e "
SELECT column_name, data_type
FROM information_schema.columns
WHERE table_schema='epicsales_db' AND table_name='employees';
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+-------------+-----------+
| column_name | data_type |
+-------------+-----------+
| employee_id | int       |
| first_name  | varchar   |
| last_name   | varchar   |
| email       | varchar   |
| dob         | date      |
| sex         | varchar   |
| start_date  | date      |
| end_date    | date      |
| pay_rate    | decimal   |
| role        | varchar   |
| street      | varchar   |
| suite       | varchar   |
| city        | varchar   |
| state       | varchar   |
| postal      | varchar   |
| country     | varchar   |
+-------------+-----------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate), 2), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------------+
| flag               |
+--------------------+
| deadface{$7391.20} |
+--------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate),2), '}') AS flag
FROM employees
WHERE role IN ('CEO','CTO','CFO')
  AND (end_date IS NULL OR end_date > CURRENT_DATE());
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------------+
| flag               |
+--------------------+
| deadface{$7050.85} |
+--------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate),2), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------------+
| flag               |
+--------------------+
| deadface{$7391.20} |
+--------------------+
(base) ss@Satwik:~$ deadface{$7391.20}
deadface{391.20}: command not found
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate),2), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+--------------------+
| flag               |
+--------------------+
| deadface{$7391.20} |
+--------------------+
(base) ss@Satwik:~$ mysql -h env01.deadface.io -P 3306 -u epicsales -p'Slighted3-Charting-Valium' epicsales_db -e "
SELECT CONCAT('deadface{$', ROUND(SUM(pay_rate),10), '}') AS flag
FROM employees
WHERE role IN ('CEO', 'CTO', 'CFO');
"
mysql: [Warning] Using a password on the command line interface can be insecure.
+----------------------------+
| flag                       |
+----------------------------+
| deadface{$7391.2000000000} |
+----------------------------+
(base) ss@Satwik:~$
````