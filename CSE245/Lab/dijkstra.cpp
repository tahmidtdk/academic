#include<bits/stdc++.h>

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli(f_n) freopen(f_n,"r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define fi first
#define se second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
const long long inf = 1000000000LL;
using namespace std;




#define PAIR pair<int, int>
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};
              // Code starts from here


vector<int>graph[1000];
int cost[1000][1000];
int dis[1000];

void inf_def(int n){
    repe(i, 1, n){
        dis[i]=inf;
    }
}

void dijkstra(int src){
    priority_queue<int>Q;
    Q.push(src);
    dis[src]=0;
    while(!Q.empty()){
        int u = Q.top();
        Q.pop();
        rep(i, 0, graph[u].size()){
            int v = graph[u][i];
            if(dis[u]+ cost[u][v]<dis[v]){
                dis[v]=dis[u]+ cost[u][v];
                Q.push(v);
            }
        }
    }

}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli("in_dij.txt");
//flo();

    int n, u, v, w;
    pf("Enter number of nodes: ");
    sfi(n);
    while(true){
        sfi2(u, v); sfi(w);
        if(u>0 and v>0){
            graph[u].pb(v);
            cost[u][v]=w;
        }
        if(u==-1 and v==-1) break;
    }
    inf_def(n);
    pf("Enter src: ");
    int src;
    sfi(src);
    dijkstra(src);
    bl;
    repe(i, 1, n){
        pf("Node: %d - distance: %d\n", i, dis[i]);
    }
    return 0;
}
