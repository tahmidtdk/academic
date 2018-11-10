select table_name from user_tables;  --show all table name for current user

--lab actibity 1
create table student(
	id char(5),
	name varchar2(20),
	dept_name varchar2(20),
	tot_cred number,
	primary key (id)
);
	
	
create table takes(
	id char(5),
	course_id char(6),
	sec_id number,
	semester varchar2(10),
	year number,
	grade varchar2(5) not null,
	primary key (id, course_id, sec_id, semester, year),
	foreign key (id) references student(id),
	check (year>=1996)
);


--lab actibity 2

alter table student add dob date; --add a new attb in table student

alter table student drop column dob; --drop a attb in table student


 -- add mulpiple attbs
alter table student add(   
	dob date,
	blood_group varchar(10) not null,
	dummy number
);


alter table student drop (dob, blood_group, dummy);

alter table takes modify course_id varchar2(10); --modify datatype

alter table takes rename column course_id to c_id; --rename column name

alter table takes rename to takes1; -- rename table name

create table course(
	course_id char(6),
	title varchar2(20),
	dept_name varchar2(20),
	credits number
);

-- add primary key after create table
alter table course add constraint course_pk primary key (course_id);

-- slow all constraint for current user (spring18)
select constraint_name, table_name, column_name from user_cons_columns;



-- lab actibity 3

-- for unique row values 
select distinct name, id from instructor;

select id, name, salary/12 from instructor; --return values with formula
select id, name, salary/12 as monthly salary  from instructor; --return values with formula modify column name
select id as identifier, name, salary/12 as monthly salary from instructor;


--karteshian product for using (,) it will be karteshian by using condition (where) for remove invilid information 
select * from instructor, department where instructor.dept_name=department.dept_name;

--natural join 

select * from instructor natural join department;

-- delete row of a table name student
delete from student where id ='12345';

--update attib

update department set dept_name = 'CE' where dept_name='CSE';
