drop table student cascade constraints;
drop table depertment cascade constraints;
drop table instructor cascade constraints;
drop table advisor cascade constraints;
drop table section cascade constraints;
drop table course cascade constraints;
drop table takes cascade constraints;
drop table teaches cascade constraints;


create table student(
	id char(15) not null,
	name varchar2(20),
	dept_name varchar2(15),
	tot_cred number(10),
	primary key(id)
);

create table depertment(
	dept_name varchar2(15) not null,
	building char(10),
	budget number(15),
	primary key(dept_name)
);

create table instructor(
	id char(15) not null,
	name varchar2(20),
	dept_name varchar2(15),
	salary number(10),
	primary key(id),
	foreign key(dept_name) references depertment(dept_name)
);

create table advisor(
	s_id char(15) not null,
	i_id char(15) not null,
	primary key(s_id, i_id),
	foreign key(s_id) references student(id),
	foreign key(i_id) references instructor(id)
);

create table section(
	course_id char(8) not null,
	sec_id char(5),
	semester char(10),
	year number(5),
	building char(10),
	room_no number(5),
	time_slot char(10),
	primary key (course_id)
);

create table takes(
	id char(15) not null,
	course_id char(8) not null,
	sec_id char(5),
	semester char(10),
	year number(5),
	grade char(5),
	primary key(id),
	foreign key(id) references student(id),
	foreign key(course_id) references section(course_id)
);

create table teaches(
	id char(15) not null,
	course_id char(8) not null,
	sec_id char(5),
	semester char(10),
	year number(5),
	primary key(id),
	foreign key(id) references instructor(id),
	foreign key(course_id) references section(course_id)
);

insert into student values('2016-1-60-001', 'Tonmoy', 'CSE', 64);
insert into student values('2015-1-40-071', 'Tanvir', 'EEE', 88);
insert into student values('2016-3-60-045', 'Hridoy', 'CSE', 46);
insert into student values('2016-3-60-045', 'Hridoy', 'CSE', 46);

commit;
