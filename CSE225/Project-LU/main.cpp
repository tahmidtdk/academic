#include"header.h"
#include"variables.h"
#include"functions.h"


int main(){
    bool access=false;
while(true){

    int key=nav_bar();
    if(key==1){
        //input equation
        input_equation();
        access=true;
    }else if(key==2){
        //print_matrix
        if(!access){
            cout<<"Please Input Equations...";bl;bl;
            Sleep(700);
            continue;
        }
        print_matrix();
    }else if(key==3){
        //Triangular Factorisation
        if(!access){
            cout<<"Please Input Equations...";bl;bl;
            Sleep(700);
            continue;
        }
        cal_upper_lower();
        while(true){
            int key2=oparate_menu();
            if(key2==1){
    //                Print Upper Matrix
                print_mat_U();
            }else if(key2==2){
    //            Print Lower Matrix
                print_mat_L();
            }else if(key2==3){
    //            Calculate Solution
                calculate_eqn();
            }else if(key2==0){
                //return to main
                break;
            }else{
                bl;
                cout<<"Invalid Input...";bl;
                Sleep(700);
            }
        }
    }else if(key==0)
        return 0;
    else{
        bl;
        cout<<"Invalid Input...";bl;
        Sleep(700);
    }

}
return 0;
}
