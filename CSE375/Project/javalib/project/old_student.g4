grammar exp1;	

start:	student_info ;

student_info 	: 		name ' ' '(' id ')' ' ' '(' address ')' ' ' '(' phone_num ')';

name			: 		WORD ;

WORD 			: 		[ a-z | A-Z | ' ' | '.' ]+ ;

id				:		year divider semester divider dept_code divider roll ;

year			:		INT ;

divider			:		'-' ;

semester		:		'1'

						| '2'
					
						| '3' ;
					
roll			:		INT ;
	
dept_code		:		'50' | '60' | '70' ;

address			:		ADD ;

ADD				:		[ a-z | A-Z | ',' | '.' | ' ' ]+ ;

phone_num		:		INT ;

INT				:		[0-9]+ ;

WS 				: 		[ \r\n\t] -> skip ;