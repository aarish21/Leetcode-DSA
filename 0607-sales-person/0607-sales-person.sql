# Write your MySQL query statement below
Select name from SalesPerson where sales_id NOT IN (Select sales_id from orders JOIN company ON orders.com_id = company.com_id where company.name = 'RED');