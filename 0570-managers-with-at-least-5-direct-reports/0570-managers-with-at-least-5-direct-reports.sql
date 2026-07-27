# Write your MySQL query statement below
select a.name
from employee A join employee B
on a.id = b.managerid
group by a.id
having count(a.id) >=5