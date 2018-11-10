#include"headerfile.h"
#include"globalvariables.h"
//custom header file
#include"function.h"



int main(){

homepage:
    int key=main_nav();
    if(key==1 or !key)
        all_access=true;

    if(!all_access){
        cout<<"You must input graph data first."<<endl;
        Sleep(700);
        goto homepage;
    }

    switch(key){
        case 1:
            input_menu();
            goto homepage;
            break;
        case 2:
            //print matrix
            print_mat(g1.ro_co);
            bl;bl;
            cout<<"Press any key to return ";
            if(getch()){
                goto homepage;
            }
            break;
        case 3:
            //Check the graph is conntected or
                bfs(1);
                {
                    bool check=true;
                    repe(i, 1, g1.ro_co){
                        if(!visit[i]){
                            debug(i);
                            debug(visit[i]);
                            int j;
                            cin>>j;
                            check=false;
                        }
                    }
                    bar();
                    if(check)
                        cout<<"This is a conntected graph."<<endl;
                    else
                        cout<<"This is not conntected graph"<<endl;
                    bl;bl;
                    cout<<"Press any key to return.";
                    if(getch())
                    goto homepage;
                }
            break;
        case 4:
            //Find the fastest route to visit the city
                {
                short_level:
                    int key=fast_menu();
                    if(key==1){
                        //Find all the cities minimum cost from a source
                        bar();
                        cout<<"Enter Your Source: ";
                        int src;
                        cin>>src;
                        bar();
                        print_dis(src, g1.ro_co);

                    }else if(key==2){
                        //Find the shortest path and print the path
                        bar();
                        int src, des;
                        cout<<"Enter source: ";
                        cin>>src;
                        cout<<"Enter your destination: ";
                        cin>>des;
                        print_path(src, des);
                    }else
                        goto homepage;
                    bl;bl;
                    cout<<"Press any key to return.";
                    if(getch())
                        goto short_level;
                    }
            break;
        case 0:
            //exit program``
            return 0;
            break;
        default:
            cout<<"Invalid Input!!!"<<endl;
            Sleep(600);
            goto homepage;
            break;
    }

    return 0;
}
