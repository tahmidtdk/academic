-- task 2
create table country(
  country_code number primary key,
  country_name varchar2(20),
  file_lob blob,
  file_name varchar2(100),
  file_mimetype varchar2(50),
  file_updatedate varchar2(50),
  file_characterset varchar2(50)
);
create table player(
  player_id number primary key,
  player_name varchar2(20),
  country_code number,
  file_lob blob,
  file_name varchar2(100),
  file_mimetype varchar2(50),
  file_updatedate varchar2(50),
  file_characterset varchar2(50),
  foreign key (country_code) references country
);

-- task 3
create sequence country_seq start with 1 increment by 1;
create sequence player_seq start with 1001 increment by 1;

-- task 5
select country_name, country_code
from country;

-- task 6

select "COUNTRY_CODE", 
"COUNTRY_NAME",
decode (nvl(dbms_lob.getlength(FILE_LOB),0),0,null,
       '<img alt = "Alter text" src="' || 
       apex_util.get_blob_file_src('P3_FILE_LOB',COUNTRY_CODE)  ||
       ' "width = "75"/>') "IMAGE", 
"FILE_NAME",
"FILE_MIMETYPE",
"FILE_UPDATEDATE",
"FILE_CHARACTERSET"
from "#OWNER#"."COUNTRY" 
