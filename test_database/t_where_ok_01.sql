select *
from Customers
where not (city = 'Paris' or city = 'Mexico')
order by custid desc;

