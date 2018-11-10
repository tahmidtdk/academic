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

int graph[1000][1000];
int cost[1000][1000];
int dis[1000];

void inf_def(int n){
    repe(i, 1, n){
        dis[i]=inf;
    }
    repe(i, 1, n){
        repe(j, 1, n){
           graph[i][j]=0;
           graph[j][i]=0;

        }
    }
}


void Bellman_Ford(int src, int n){

    repe(i, 1, n){
        dis[i]=inf;
    }
    dis[src]=0;
int temp_dis=0;
    repe(k, 1, n-1){
        repe(i, 1, n){
            repe(j, 1, n){
                if(graph[i][j])
                    temp_dis=dis[i]+graph[i][j];
                if(temp_dis<dis[j])
                    dis[j]=temp_dis;
            }
        }
    }

    repe(i, 1, n){
        repe(j, 1, n){
            if(dis[j]+graph[j][i]<dis[i]){
                    bl;bl;
                printf("The graph contains negative cycle\n\n");
                return;
            }
        }
    }
}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli("Bellman.txt");
//flo();

    int n, u, v, w;
    pf("Enter number of nodes: ");
    sfi(n);
    inf_def(n);
    bl;
    while(true){
        sfi2(u, v); sfi(w);
        if(u>0 and v>0){
            graph[u][v]=w;
        }
        if(u==-1 and v==-1) break;
    }

    Bellman_Ford(5, 5);
    repe(i, 1, n){
        pf("Node: %d - Distance: %d\n", i, dis[i]);
    }

    return 0;
}
