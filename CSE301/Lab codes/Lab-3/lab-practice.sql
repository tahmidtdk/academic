
--1.
select branch_name, branch_city, assets
from branch
where assets>1000000;

--2.
select account_number, balance
from account
where branch_name ='Downtown' or (balance between 600 and 750);

--3.
select account_number
from account natural join branch
where branch_city='Rye';

--4.
select loan_number
from customer natural join borrower natural join loan
where amount>=1000 and customer_city = 'Harrison';

--5.
select *
from account
order by balance desc;

--6.
select *
from customer
order by customer_city;

--7.
(select customer_name
from account natural join depositor)
intersect
(select customer_name
from loan natural join borrower);

--8.
(select customer_name, customer_street, customer_city
from customer natural join account natural join depositor)
union
(select customer_name, customer_street, customer_city
from customer natural join loan natural join borrower);

--9.
(select customer_name, customer_city
from customer natural join borrower natural join loan)
minus
(select customer_name, customer_city
from customer natural join depositor natural join account);

--10.
select sum(assets)
from branch;

--11. 
select branch_name, avg(balance)
from account
group by branch_name;

--12.
select branch_city, avg(balance)
from account natural join branch
group by branch_city;

--13.
select branch_name, min(amount)
from branch natural join loan
group by branch_name;

--14.
select branch_name, count(distinct loan_number)
from branch natural join loan
group by branch_name;

--15.
select customer_name, account_number
from account natural join depositor
where balance = (select max(balance)
from account);