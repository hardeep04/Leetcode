# Write your MySQL query statement below
select Product.product_name, Sales.year, Sales.price
from sales left join product
on product.product_id = sales.product_id