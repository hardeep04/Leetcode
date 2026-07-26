# Write your MySQL query statement below
select B.id
from Weather A, weather B
where Datediff(B.recordDate,A.recordDate)=1 AND B.temperature > A.temperature;