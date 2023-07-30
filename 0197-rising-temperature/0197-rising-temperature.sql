# Write your MySQL query statement below
Select a.id from weather a, weather b where DATEDIFF(a.recordDate,b.recordDate) =1 AND a.Temperature>b.Temperature;