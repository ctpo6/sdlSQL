select *
from Customers C
join Orders O
    on C.custid = O.custid
where C.city = 'Paris';

