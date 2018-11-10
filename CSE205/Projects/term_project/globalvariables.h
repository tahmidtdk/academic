
#define no_si 2000

//data structure declare
struct graphsize{
    int ro_co, edges;
    graphsize(int rc, int e):ro_co(rc), edges(e){
        //constructor
    };
    graphsize(){;
        //empty constructor
    }
};

///global variable declare

vector<int>graph[no_si];
int cost[no_si][no_si];
bool visit[no_si];
int dis[no_si];
int par[no_si];
bool all_access=false;
graphsize g1(0, 0);
int tree_build_cost[100][100];
vector<int>tree_nodes;
