drop table classroom cascade constraints;
drop table department cascade constraints;
drop table course cascade constraints;
drop table instructor cascade constraints;
drop table section cascade constraints;
drop table teaches cascade constraints;
drop table student cascade constraints;
drop table takes cascade constraints;
drop table advisor cascade constraints;
drop table time_slot cascade constraints;
drop table prereq cascade constraints;
drop table users cascade constraints;

create table classroom
	(classroom_id 		number,
	 building		varchar(15),
	 room_number		varchar(7),
	 capacity		numeric(4,0),
	 primary key (classroom_id)
	);

create table department
	(dept_id		number,
	 dept_name		varchar(20), 
	 building		varchar(15), 
	 budget		        numeric(12,2) check (budget > 0),
	 primary key (dept_id)
	);

create table course
	(course_serial 		number,
	 course_id		varchar(8), 
	 title			varchar(50), 
	 dept_id		number,
	 credits		numeric(2,0) check (credits > 0),
	 primary key (course_serial),
	 foreign key (dept_id) references department
		on delete set null
	);

create table instructor
	(instructor_id		number, 
	 name			varchar(20) not null, 
	 dept_id		number, 
	 salary			numeric(8,2) check (salary > 29000),
         instructor_image_lob	blob,
	 instructor_image_name varchar2(100),
 	 instructor_image_mimetype varchar2(100),
	 instructor_image_updatedate varchar2(100),
	 instructor_image_characterset varchar2(100),
	 primary key (instructor_ID),
	 foreign key (dept_id) references department
		on delete set null
	);

create table time_slot
	(time_slot_serial	number,
	 time_slot_id		varchar(1),
	 day			varchar(1),
	 start_hr		numeric(2) check (start_hr >= 0 and start_hr < 24),
	 start_min		numeric(2) check (start_min >= 0 and start_min < 60),
	 end_hr			numeric(2) check (end_hr >= 0 and end_hr < 24),
	 end_min		numeric(2) check (end_min >= 0 and end_min < 60),
	 primary key (time_slot_serial)
	);


create table section
	(section_serial		number,
	 course_serial		number, 
         sec_id			number,
	 semester		varchar(6)
		check (semester in ('Fall', 'Spring', 'Summer')), 
	 year			numeric(4,0) check (year > 1701 and year < 2100), 
	 classroom_id		number,
	 time_slot_serial	number,
	 primary key (section_serial),
	 foreign key (course_serial) references course
		on delete cascade,
	 foreign key (classroom_id) references classroom
		on delete set null,
	 foreign key (time_slot_serial) references time_slot
		on delete set null
	);

create table teaches
	(teaches_serial		number,
	 instructor_ID		number, 
	 section_serial 	number,
	 primary key (teaches_serial),
	 foreign key (section_serial) references section
		on delete cascade,
	 foreign key (instructor_ID) references instructor
		on delete cascade
	);

create table student

	(student_serial 	number,
	 student_ID		varchar(13), 
	 name			varchar(20) not null, 
	 dept_id		number, 
	 tot_cred		numeric(3,0) default 0 check (tot_cred >= 0),
	 student_image_lob     blob,    
	 student_image_name varchar2(100),
 	 student_image_mimetype varchar2(100),
	 student_image_updatedate varchar2(100),
	 student_image_characterset varchar2(100),   
	 primary key (student_serial),
	 foreign key (dept_id) references department
		on delete set null
	);

create table takes
	(takes_serial number,
	 student_serial		number, 
	 section_serial		number, 
	 grade		        varchar(2),
	 primary key (takes_serial),
	 foreign key (section_serial) references section
		on delete cascade,
	 foreign key (student_serial) references student
		on delete cascade
	);

create table advisor
	(advisor_serial		number,
	 student_serial		number,
	 instructor_ID		number,
	 primary key (advisor_serial),
	 foreign key (instructor_id) references instructor
		on delete set null,
	 foreign key (student_serial) references student
		on delete cascade
	);

create table prereq
	(prereq_serial		number,
	 course_id		number, 
	 prereq_id		number,
	 primary key (prereq_serial),
	 foreign key (course_id) references course
		on delete cascade,
	 foreign key (prereq_id) references course
	);

create table users (
	user_id number,
	user_name varchar2(20),
	user_password varchar2(20),
	user_activated number,
	primary key (user_id)
);

create sequence classroom_seq start with 1 increment by 1;

create sequence department_seq start with 101 increment by 1;

create sequence course_seq start with 201 increment by 1;

create sequence instructor_seq start with 301 increment by 1;

create sequence time_slot_seq start with 401 increment by 1;

create sequence section_seq start with 501 increment by 1;

create sequence teaches_seq start with 601 increment by 1;

create sequence student_seq start with 701 increment by 1;

create sequence takes_seq start with 801 increment by 1;

create sequence advisor_seq start with 901 increment by 1;

create sequence prereq_seq start with 1001 increment by 1;

create sequence users_seq start with 1101 increment by 1;

commit;