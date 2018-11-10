#include"header.h"
#include"stStack.h"
#include"stQueue.h"
#include"functions.h"

using namespace std;

int main(){


    while(true){
        userna_global="Not logged in...";
       int key = main_Menu();
       if(key==1){
            //user
            bool choi = user_menu();


       }else if(key==2){
//            admin
                bool choi =admin_login("admin", "1234");
                if(choi)admin_menu();
       }else if(key==99){
             break;
       }else{
            Sleep(500);
       }
    }


    return 0;
}
