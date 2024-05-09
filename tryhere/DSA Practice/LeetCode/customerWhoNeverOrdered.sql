# Write your MySQL query statement below
# 183 Customers Who Never Order
select name as Customers from Customers where id NOT IN (select customerId from Orders)