# Write your MySQL query statement below
Select name as 'name', bonus as 'bonus' from Employee left join Bonus on Employee.empId = Bonus.empId where (Bonus.bonus <1000 or bonus.bonus is null);