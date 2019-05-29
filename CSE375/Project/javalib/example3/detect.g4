grammar detect;

student : (start NEWLINE)*;

start : year seperator semester seperator department seperator id;

year : ID;

semester : summer | spring | fall;

summer : '2';
spring :'1';
fall : '3';

department : cse | bba | pharmacy;

cse : '60';
bba : '10';
pharmacy : '70';


seperator : '-';
id : ID;

ID : [0-9]+; 

NEWLINE : [\r\n]+;