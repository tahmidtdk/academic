--1.
select account_no
from account
where balance>10000;

--2.
select customer_name
from customer
where customer_city = 'Dhaka';

--3.
select customer_no
from customer
where customer_name	like 'A%';

--4.
select distinct customer_city
from customer;

--5.
select *
from customer natural join depositor;

--6.
select customer_name, customer_city
from account natural join depositor natural	join customer;

--7.
select customer_no, customer_name, customer_city
from account natural join depositor natural join customer
where balance>3000;

--8.
select account_no, balance
from account natural join depositor natural join customer
where (balance between 5000 and 10000)
and customer_city = 'Khulna';

--9.
update customer
set customer_city = 'Rajshahi'
where customer_no = 'C-101';
