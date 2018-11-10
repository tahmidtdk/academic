
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

void print_nodes(){
    cout<<"Nodes are: ";
    rep(i, 0, g1.ro_co){
        cout<<i<<" ";
    }bl;bl;
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
    cout<<"1) Find Minimum cost from a source to visit all cities.";bl;bl;
    cout<<"2) Find minimum cost from source to destination to visit all cities.";bl;bl;
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
    rep(i, -1, n){
        if(i==-1){
            cout<<"   "<<" "<<" ";
            continue;
        }
        if(i<10)
            cout<<" | "<<" "<<i;
        else
            cout<<" | "<<i;
        cont+=5;
    }puts(" |");

    cont+=3;

    pfs("       -");
    rep(i, 0, cont){
        cout<<"-";
    }bl;

    rep(i, 0, n){
        pfs("       | ");
        if(i<10)
            cout<<" "<<i<<" |";
        else if(i>=10)
            cout<<i<<" |";
        rep(j, 0, n){
            if(j==0) pfs(" ");
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



int fact(int n){
    int ans=1;
    for(int i=n; i>0; i--){
        ans*=i;
    }
    return ans;
}


void print_dis(int src, int n){
    bar();
    string nodes_per;
    rep(i, 0, n){
        nodes_per.pb(i+'0');
    }
    int factorial=fact(nodes_per.size());
    rep(i, 0, factorial)
        new_num[i].clear();
    int ii=0;
    rep(k, 0, factorial){
        next_permutation(nodes_per.begin(), nodes_per.end());
        if(nodes_per[0]-'0'==src){
            new_num[ii]=nodes_per;
            ii++;
        }
    }
    int mmn=INT_MAX;
    int path_id;
    rep(i, 0, ii){
    int dist=0;
        rep(j, 1, new_num[i].size()){
            int bb=new_num[i][j-1]-'0';
            int ff=new_num[i][j]-'0';
            dist+=(cost[bb][ff]);
        }
        if(mmn>dist){
            mmn=dist;
            path_id=i;
        }
    }
    bl;
    cout<<"Minimum Cost to Visit: "<<mmn<<endl;bl;
    cout<<"Path Direction: "<<endl;bl;
    cout<<"\t";
    rep(i, 0, new_num[path_id].size()){
        cout<<new_num[path_id][i];
        if(i<new_num[path_id].size()-1)
            cout<<" -> ";
    }

}


void print_dis_2(int src, int n, int des){
    bar();
    string nodes_per;
    rep(i, 0, n){
        nodes_per.pb(i+'0');
    }

    int factorial=fact(nodes_per.size());
    rep(i, 0, factorial)
        new_num[i].clear();
    int ii=0;
    rep(k, 0, factorial){
        next_permutation(nodes_per.begin(), nodes_per.end());
        if(nodes_per[0]-'0'==src and nodes_per[nodes_per.size()-1]){
            new_num[ii]=nodes_per;
            ii++;
        }
    }
    int mmn=INT_MAX;
    int path_id;
    rep(i, 0, ii){
    int dist=0;
        rep(j, 1, new_num[i].size()){
            int bb=new_num[i][j-1]-'0';
            int ff=new_num[i][j]-'0';
            dist+=(cost[bb][ff]);
        }
        if(mmn>dist){
            mmn=dist;
            path_id=i;
        }
    }
    bl;
    cout<<"\t\tSource "<<src<<" to destination "<<des<<" :";bl;bl;
    cout<<"Minimum Cost to Visit: "<<mmn<<endl;bl;
    cout<<"Path Direction: "<<endl;bl;
    cout<<"\t";
    rep(i, 0, new_num[path_id].size()){
        cout<<new_num[path_id][i];
        if(i<new_num[path_id].size()-1)
            cout<<" -> ";
    }

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





void input_random(){    //build random tree or connected graph

    bar();
    ofstream grp_in;
    grp_in.open("graph_file.txt");


    memset(nodes, 0, sizeof(nodes));
    int n;
    cout<<"Enter the number of spots: ";
    sfi(n);
    nodes_num=n;
    int jj=n-1;
    int edges_num=(jj*(jj+1))/2;
    grp_in<<n<<" "<<edges_num<<endl;  //write n=edge & no=number of nodes
    srand(time(0));
    rep(i, 0, n){
        rep(j, 0, n){
            if(i==j) continue;

                if(!nodes[i][j] and !nodes[j][i]){
                int cc=rand()%20+1;
                graph_cal[i][j]=cc;
                graph_cal[j][i]=cc;
                nodes[i][j]=true;
                nodes[j][i]=true;
                grp_in<<i<<" "<<j<<" "<<cc<<endl;

            }
        }
    }

    grp_in.close();
    if(nodes_num>0)
    {
        bl;bl;
        cout<<"Input Successfully"<<endl;
        Sleep(300);
    }
}
