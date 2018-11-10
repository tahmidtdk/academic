
///predeclare function
void gettime_date();
void input_random();
int main();

///all functions
void bar(){
    system("cls");
    cout<<"              ------------------------ Virtual Tourist's Guide --------------------"<<endl<<endl;
    gettime_date();
    bl;bl;
}

void gettime_date(){                                    ///return time and date
    time_t t=time(NULL);
    char tmstr[100];
    if(strftime(tmstr, sizeof(tmstr), "%A %c", localtime(&t))){
        cout<<setw(83)<<tmstr<<endl<<endl;
    }
}


    //main navbar
int main_nav(){
    bar();
    cout<<"\t1) Input Data";bl;bl;
    cout<<"\t2) Check data input adjacency matrix";bl;bl;
    cout<<"\t3) Check the graph is connected or not";bl;bl;
    cout<<"\t4) Find the fastest route to visit the city ";bl;bl;
    cout<<"\t0) Exit ";bl;bl;
    int key;
    cin>>key;
    return key;
}


        //fastest route visit menu
int fast_menu(){

rec_again:

    bar();
    cout<<"1) Find all the cities minimum cost from a source.";bl;bl;
    cout<<"2) Find the shortest path from source to destination with minimum cost.";bl;bl;
    cout<<"0) Return to main Menu.";bl;bl;
    int key;
    cin>>key;
    if(key==1 or key==2 or !key)
        return key;
    else{
        cout<<"Invalid Input!!!"<<endl;
        Sleep(600);
        goto rec_again;
    }
}

        ///read graph data from user using adjacency list

graphsize read_graph(){
    bar();
    rep(i, 0, 2000){
        graph[i].clear();
    }
    memset(cost, 0, sizeof(cost));
    cout<<"Enter the number of nodes: ";
    int n, m;
    sfi(n);
    cout<<"Enter the number of edges: ";
    sfi(m);
    int u, v, w;
    cout<<"Enter the connected nodes with there weight[u v w]: ";bl;
    rep(i, 0, m){
        sfi2(u, v);sfi(w);
        graph[u].pb(v);
        graph[v].pb(u);
        cost[v][u]=w;
        cost[u][v]=w;
    }
    return graphsize(n, m);
}
            ///read input data from file
graphsize file_read_graph(){
    bar();
    rep(i, 0, 2000){
        graph[i].clear();
    }
    memset(cost, 0, sizeof(cost));
    file(gp_in, "graph2.txt")     //file input open
    int n, m;
    gp_in>>n>>m;
    int u, v, w;
    rep(i, 0, m){
        gp_in>>u>>v>>w;
        cout<<u<<" "<<v<<" "<<w<<endl;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[v][u]=w;
        cost[u][v]=w;

    }
    gp_in.close(); //file input close

    int o=33, p=33, q=33, r=33, s=33;
          for( ; ; ){
                bar();
                printf("\Input data is reading %c %c %c %c %c\n", q, o, p, r, s);
                //Sleep(2);
                if(q<46){
                    q++;
                }
                else if(q==46 && o<46)
                    o++;
                else if(q==46 && o==46 && p<46)
                    p++;
                else if(q==46 && o==46 && p==46 && r<46)
                    r++;
                else if(q==46 && o==46 && p==46 && r==46 && s<46)
                    s++;
                else
                    break;


          }
    return graphsize(n, m);
}


graphsize rand_graph_input(){
    bar();
    rep(i, 0, 2000){
        graph[i].clear();
    }
    memset(cost, 0, sizeof(cost));
    file(gp_in, "graph_file.txt")     //file input open
    int n, m;
    gp_in>>n>>m;
    int u, v, w;
    rep(i, 0, m){
        gp_in>>u>>v>>w;
        cout<<u<<" "<<v<<" "<<w<<endl;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[v][u]=w;
        cost[u][v]=w;

    }
    gp_in.close(); //file input close

    int o=33, p=33, q=33, r=33, s=33;
          for( ; ; ){
                bar();
                printf("\Input data is reading %c %c %c %c %c\n", q, o, p, r, s);
                //Sleep(2);
                if(q<46){
                    q++;
                }
                else if(q==46 && o<46)
                    o++;
                else if(q==46 && o==46 && p<46)
                    p++;
                else if(q==46 && o==46 && p==46 && r<46)
                    r++;
                else if(q==46 && o==46 && p==46 && r==46 && s<46)
                    s++;
                else
                    break;


          }
    return graphsize(n, m);
}



            //print the values as adjacency matrix
void print_mat(int n){
    bar();
    if(!n){
        cout<<"No data is input. Please input graph data first.";bl;bl;
        Sleep(600);
        return;
    }

    int cont=2;

    pfs("      ");
    repe(i, 0, n){
        if(i<10)
            cout<<" | "<<" "<<i;
        else
            cout<<" | "<<i;
        cont+=5;
    }puts(" |");

    cont-=2;

    pfs("       -");
    rep(i, 0, cont){
        cout<<"-";
    }bl;

    repe(i, 1, n){
        pfs("       | ");
        if(i<10)
            cout<<" "<<i<<" |";
        else if(i>=10)
            cout<<i<<" |";
        repe(j, 1, n){
            if(j==1) pfs(" ");
            if(cost[i][j]<10)
                cout<<0<<cost[i][j]<<" | ";   ///using cost[i][j]
            else
                cout<<cost[i][j]<<" | ";   ///using cost[i][j]
        }bl;
    }

    pfs("       -");
    rep(i, 0, cont){
        cout<<"-";

    }bl;
}

        ///Breadth-first search

bool bfs(int src){
    memset(visit, 0, sizeof(visit));
    priority_queue<int>Q;
    Q.push(src);
    while(!Q.empty()){
        int u= Q.top();
        Q.pop();
        visit[u]=true;
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(!visit[v]){
                visit[v]=true;
//                cout<<u<<"--"<<v<<endl;
                Q.push(v);
            }
        }
    }
}

        ///Breadth-first search finding the shortest path
void dijkstra(int src){
    memset(par, -1, sizeof(par));
    priority_queue<int>Q;
    rep(i, 0, no_si){
        dis[i]=INT_MAX;
    }
    Q.push(src);
    dis[src]=0;
    while(!Q.empty()){
        int u=Q.top();
        Q.pop();
        rep(i, 0, graph[u].size()){
            int v=graph[u][i];
            if(((ll)dis[u]+cost[u][v])<dis[v]){
                dis[v]=dis[u]+cost[u][v];
                par[v]=u;
                Q.push(v);
            }
        }
    }
}

void print_path(int src, int des){
    bar();
    dijkstra(src);
    cout<<"                    Travelling from "<<src<<" to "<<des;bl;bl;bl;bl;
    cout<<"It needs cost ["<<dis[des]<<"] to reach "<<des;bl;bl;
    vector<int>paths;
    map<int, bool>mp;

    paths.pb(src);
    mp[src]=true;
    mp[des]=true;

    repe(i, 1, des){
        if(!mp[par[i]] and par[i]>0){
            paths.pb(par[i]);
            mp[par[i]]=true;
        }
    }
    paths.pb(des);
    cout<<"The path direction : ";
    if(dis[des]){
        rep(i, 0, paths.size()){
            cout<<paths[i];
            if(i<(paths.size()-1))
                cout<<" -> ";
        }
    bl;bl;
    }else{
        cout<<src<<" -> "<<des<<endl;
        bl;
    }
    cout<<"                      Happy journey... :)";bl;
}


void print_dis(int src, int n){
    dijkstra(src);
    cout<<"               Minimum Cost Calculator from "<<src<<" to other cities    ";bl;bl;bl;
    repe(i, 1, n){
        cout<<"From "<<src<<" to "<<i<<" minimum cost is: "<<dis[i];bl;
    }bl;
}


void input_menu(){
    bar();
    cout<<"\t1) Input Data Manually";bl;bl;
    cout<<"\t2) Input Data From File";bl;bl;
    cout<<"\t3) Random Input Data";bl;bl;
    cout<<"\t0) Return To Main Menu";bl;bl;
    int key;
    cin>>key;
    if(key==0)
        main();
    else if(key==1)
        g1=read_graph();
    else if(key==2)
        g1=file_read_graph();
    else if(key==3){
        //random input
        input_random();
        g1=rand_graph_input();
    }
    else{
        cout<<"Invalid Input!!!"<<endl;
        Sleep(700);
        input_menu();
    }

}




bool found(int src){
    int id=upper_bound(tree_nodes.begin(), tree_nodes.end(), src)-tree_nodes.begin();
    if(tree_nodes[id-1]==src)
        return true;
    else
        return false;
}


void input_random(){    //build random tree or connected graph
    tree_nodes.clear();
    bar();
    memset(tree_build_cost, 0, sizeof(tree_build_cost));
    ofstream grp_in;
    grp_in.open("graph_file.txt");
    int n, no;
    ll time_pev=time(NULL);
    srand(time(0));
    no= (rand()%5)+4;
    n =no*2;
    grp_in<<no<<" "<<n<<endl;
    tree_nodes.pb(1);
    while(n){
        if((time(NULL)-time_pev)>3){
            cout<<"[Warning]: It will be take some time to make graph as connected.";bl;
            cout<<"You can wait or reopen the program\n"<<endl;
            cout<<"Press [1] to try again."<<endl;
            cout<<"Press [2] to return. [Without Input]"<<endl;
            int key;
            cin>>key;
            if(key==1)
                input_random();
            else
                break;
            }
    int length = tree_nodes.size();
    int ind=rand() % length;
    int ran_num = tree_nodes[ind];
    int ran_num2=(rand()%no)+1;
    int print_rand=(rand()%2)+1;
    int rand_tree_build_cost=(rand()%20)+1;
        tree_nodes.pb(ran_num2);
        rep(i, 1, no){
            if(!found(i))
                ran_num2=i;
        }
    if(ran_num2!=ran_num){
        if(print_rand==1 and !tree_build_cost[ran_num][ran_num2] and !tree_build_cost[ran_num2][ran_num]){
            grp_in<<ran_num<<" "<<ran_num2<<" "<<rand_tree_build_cost<<endl;
            tree_build_cost[ran_num][ran_num2]=rand_tree_build_cost;
            n--;
        }
        else if(!tree_build_cost[ran_num2][ran_num] and !tree_build_cost[ran_num][ran_num2]){
            grp_in<<ran_num2<<" "<<ran_num<<" "<<rand_tree_build_cost<<endl;
            tree_build_cost[ran_num2][ran_num]=rand_tree_build_cost;
            n--;
            }
        }
    }
//    fclose (stdout);
    grp_in.close();
}
