create table person(
	personID number not null,
	personName varchar2(50) not null,
	personDOB date 
);

insert into person values(20180001, 'Alice', '01-JAN-92');

insert into person values(20180002, 'Bob', '03-DEC-94');

insert into person values(20180003, 'Charlie', '03-NOV-93');


select * from person;

select personName, personDOB from person where personID=20180001;