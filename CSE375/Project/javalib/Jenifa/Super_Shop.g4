grammar Super_Shop;

shop_info: (location '('product')' '('contact_number')' NEWLINE*)*;

contact_number: SPACE* NUMBER SPACE*;
product: SPACE* name SPACE* id SPACE* price SPACE*;

price: NUMBER;
name: (WORD SPACE*);
id: (WORD '-' NUMBER SPACE*);
location: (WORD SPACE* ','? SPACE*)*;


NUMBER: [0-9]+;
WORD: [a-zA-Z]+;
SPACE: ' '->skip;
NEWLINE: [\r\n]->skip;