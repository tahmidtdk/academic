delete from classroom;
delete from department;
delete from time_slot;
delete from users;

insert into classroom values (classroom_seq.nextval,'Packard', '101', '500');

insert into classroom values (classroom_seq.nextval,'Painter', '514', '10');

insert into classroom values (classroom_seq.nextval,'Taylor', '3128', '70');

insert into classroom values (classroom_seq.nextval,'Watson', '100', '30');

insert into classroom values (classroom_seq.nextval,'Watson', '120', '50');


insert into department values (department_seq.nextval,'Biology', 'Watson', '90000');

insert into department values (department_seq.nextval,'Comp. Sci.', 'Taylor', '100000');

insert into department values (department_seq.nextval,'Elec. Eng.', 'Taylor', '85000');

insert into department values (department_seq.nextval,'Finance', 'Painter', '120000');

insert into department values (department_seq.nextval,'History', 'Painter', '50000');

insert into department values (department_seq.nextval,'Music', 'Packard', '80000');

insert into department values (department_seq.nextval,'Physics', 'Watson', '70000');


insert into time_slot values (time_slot_seq.nextval, 'A', 'M', '8', '0', '8', '50');

insert into time_slot values (time_slot_seq.nextval, 'A', 'W', '8', '0', '8', '50');

insert into time_slot values (time_slot_seq.nextval, 'A', 'F', '8', '0', '8', '50');

insert into time_slot values (time_slot_seq.nextval, 'B', 'M', '9', '0', '9', '50');

insert into time_slot values (time_slot_seq.nextval, 'B', 'W', '9', '0', '9', '50');

insert into time_slot values (time_slot_seq.nextval, 'B', 'F', '9', '0', '9', '50');

insert into time_slot values (time_slot_seq.nextval, 'C', 'M', '11', '0', '11', '50');

insert into time_slot values (time_slot_seq.nextval, 'C', 'W', '11', '0', '11', '50');

insert into time_slot values (time_slot_seq.nextval, 'C', 'F', '11', '0', '11', '50');

insert into time_slot values (time_slot_seq.nextval, 'D', 'M', '13', '0', '13', '50');

insert into time_slot values (time_slot_seq.nextval, 'D', 'W', '13', '0', '13', '50');

insert into time_slot values (time_slot_seq.nextval, 'D', 'F', '13', '0', '13', '50');

insert into time_slot values (time_slot_seq.nextval, 'E', 'T', '10', '30', '11', '45 ');

insert into time_slot values (time_slot_seq.nextval, 'E', 'R', '10', '30', '11', '45 ');

insert into time_slot values (time_slot_seq.nextval, 'F', 'T', '14', '30', '15', '45 ');

insert into time_slot values (time_slot_seq.nextval, 'F', 'R', '14', '30', '15', '45 ');

insert into time_slot values (time_slot_seq.nextval, 'G', 'M', '16', '0', '16', '50');

insert into time_slot values (time_slot_seq.nextval, 'G', 'W', '16', '0', '16', '50');

insert into time_slot values (time_slot_seq.nextval, 'G', 'F', '16', '0', '16', '50');

insert into time_slot values (time_slot_seq.nextval, 'H', 'W', '10', '0', '12', '30');


insert into users values (users_seq.nextval, 'admin', 'admin123', 1);

commit;