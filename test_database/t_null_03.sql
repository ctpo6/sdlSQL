-- contactname can be NULL
-- because result of compare with NULL is undefined, should return 0 records
select *
from Customers
where contactname = NULL;

