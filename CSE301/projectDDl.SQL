create table clients(
	cl_id varchar2(50) not null,
	cl_name varchar2(50) not null,
	cl_phone varchar(15),
	cl_address varchar(100),
	primary key(cl_id)
	);

create sequence clients_seq start with 1 increment by 1;

insert into clients values(clients_seq.nextval, 'Trump', '+916547885566', 'NY, USA');
insert into clients values(clients_seq.nextval, 'Tom', '+856455445454', 'Rome, Italy');
insert into clients values(clients_seq.nextval, 'Jane', '+91565566566', 'WS, USA');

create table pack_type(
	type_code varchar2(20) primary key not null,
	type_name varchar(20) not null
);


drop table packages;
drop table pack_type;
create table packages(
	pk_id varchar2(20) primary key,
	type_code varchar2(20),
	pk_name varchar2(50) not null,
	pk_place varchar2(100) not null,
	num_of_adlts numeric(10, 0) not null,
	num_of_child numeric(10, 0) not null,
	description varchar2(500),
	stay_ammount numeric (10,2) default 0,
	food_amount numeric(10,2) default 0,
	bus_amount numeric (10,2) default 0,
	train_amount numeric (10,2) default 0,
	air_amount numeric (10,2) default 0,
	num_days numeric(10, 0) not null,
	num_nights numeric(10, 0) not null,
	pack_image blob,
	foreign key(type_code) references pack_type(type_code)
);

create sequence packages_seq start with 101 increment by 1;