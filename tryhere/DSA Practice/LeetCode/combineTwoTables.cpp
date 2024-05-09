# Write your MySQL query statement below
# 175. Combine Two Tables

select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId;