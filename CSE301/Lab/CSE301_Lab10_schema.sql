create table my_users (
user_id number,
user_name varchar2(20),
user_password varchar2(20),
user_activated number default 0,
primary key(user_id));

create sequence my_users_seq start with 30001 increment by 1;

insert into my_users values (my_users_seq.nextval,'admin','admin123',1);

create table my_branch(id number,
name varchar2(20),
city varchar2(20), 
assets number default 0 not null,
constraint my_branch_pk primary key (id));

create table my_account(id number,
name varchar2(20),
branch_id number,
balance number default 0 not null,
constraint my_account_pk primary key (id),
constraint my_account_fk foreign key (branch_id) references my_branch(id));

create table my_deposit( id number,
account_id number,
deposit_amount number not null,
deposit_date timestamp not null,
deposit_user varchar2(20) not null,
constraint my_deposit_pk primary key (id),
constraint my_deposit_fk foreign key (account_id) references my_account(id)); 

create table my_withdraw( id number,
account_id number,
withdraw_amount number not null,
withdraw_date timestamp not null,
withdraw_user varchar2(20) not null,
constraint my_withdraw_pk primary key (id),
constraint my_withdraw_fk foreign key (account_id) references my_account(id)); 

create sequence my_branch_seq start with 101 increment by 1;
create sequence my_account_seq start with 201 increment by 1;
create sequence my_deposit_seq start with 1001 increment by 1;
create sequence my_withdraw_seq start with 2001 increment by 1;


  


