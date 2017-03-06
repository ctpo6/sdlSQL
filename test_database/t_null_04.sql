-- contactname can be NULL
-- check that row with NULL contactname are placed first
select contactname
from Customers
order by contactname;

