grammar bash;	

expression:	(command SEMICOLON NEWLINE*)* ;  //gcc code.c -o compiled




command : WORD SPACE* (peremeter | string) ;

peremeter: PARRM;
PARRM: ([-][a-zA-Z]+);

//string: KKK;
string : path | object;

path: (SPACE*( WOR_SLS))*;

object: (SPACE*( WORD))*;


//FULL_PARAM : ((SPACE*( WORD))* | (SPACE* DASH ( WORD))* );

//peremeter : (SPACE* DASH ( WORD))*;

DASH : '-';
WORD : [a-zA-Z] [a-zA-Z0-9_.]*;
WOR_SLS : [a-zA-Z] [a-zA-Z0-9/_.]*;


SEMICOLON : ';';

SPACE : ' '->skip;
NEWLINE : [\r\n]->skip;
