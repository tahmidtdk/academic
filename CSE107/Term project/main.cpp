#include<windows.h>
#include<conio.h>
#include "shares.h"
#include "user.h"
#include "extra_func.h"

int main(){

    while(true){
        userna_global="Not logged in...";

        displaybar();
        cout<<"1) Admin"<<endl<<endl;
        cout<<"2) Buyers and sallers"<<endl<<endl;
        cout<<"3) Exit"<<endl<<endl;
        int key;
        cin>>key;
        if(key==1){

            login_admin();
            userna_global="Admin";
            disadmin_bar();
        }else if(key==2){
            user_login();
            //user menu starts
            disusr_usr_bar();
        }else if(key==3)
            break;
        else{
            cout<<"Wrong keyword"<<endl<<endl;
            Sleep(600);
            main();
        }
    }
    return 0;
}
