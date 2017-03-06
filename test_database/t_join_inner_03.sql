select top(100) C.custid, O.orderid, C.companyname, C.city, O.shipcountry
from Customers C
join Orders O
    on C.custid = O.custid
where C.city = 'Paris'
order by O.shipcountry desc;

