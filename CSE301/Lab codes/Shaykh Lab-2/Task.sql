--task-1

create table account(
	account_no char(5),
	balance number not null,
	primary key(account_no),
	check (balance>0)
);

create table customer(
	customer_no char(5),
	customer_name varchar2(20) not null,
	customer_city varchar2(10),
	primary key(customer_no)
);

create table depositor(
	account_no char(5),
	customer_no char(5),
	primary key (account_no, customer_no)
);

--task-2
alter table customer add date_of_birth date;
alter table customer drop column date_of_birth;
alter table depositor rename column account_no to a_no;
alter table depositor rename column customer_no to c_no;


alter table account rename column account_no to a_no;
alter table customer rename column customer_no to c_no;

alter table depositor add constraint depositor_fk1 foreign key (a_no) references account(account_no);
alter table depositor add constraint depositor_fk2 foreign key (c_no) references customer(customer_no);


--task-3

insert into account values('A-101', 12000);
insert into account values('A-102', 6000);
insert into account values('A-103', 2500);



insert into customer values('C-101', 'Alice', 'Dhaka');
insert into customer values('C-102', 'Annie', 'Dhaka');
insert into customer values('C-103', 'Bob', 'Chittagong');
insert into customer values('C-104', 'Charlie', 'Khulna');

insert into Depositor values('A-101', 'C-101');
insert into Depositor values('A-103', 'C-102');
insert into Depositor values('A-103', 'C-104');
insert into Depositor values('A-102', 'C-103');

