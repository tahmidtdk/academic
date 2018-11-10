#include"header.h"
#include"variables.h"
#include"functions.h"

int main(){
    int round_l=-1;
main_menu:
    round_l++;
    if(main_nav()==1){
        //input Propositional Logic.
        input_proposition();
        goto main_menu;
    }else if(main_nav()==2){
        //Input variables for Proposition
        input_variables();
    }else if(main_nav()==3){
        //Show Truth Table
    }else if(main_nav()==4){
        //Judge Proposition
    }else if(main_nav()==5){
        return 0;
    }
}
