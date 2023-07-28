# Write your MySQL query statement below
SELECT distinct A.EMAIL AS 'Email' FROM PERSON AS A JOIN PERSON AS B WHERE A.ID!=B.ID AND A.EMAIL=B.EMAIL;