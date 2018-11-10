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

int knapSack(int W, int *wt, int *pr, int n)
{
   int matrix[n+1][W+1];
   pf("\n Calculating Grid: \n");
   repe(i, 0, n){
       repe(w, 0, W){

           if (i==0 or w==0)
               matrix[i][w] = 0;

           else if (wt[i-1] <= w)
                 matrix[i][w] = max(pr[i-1] + matrix[i-1][w-wt[i-1]],  matrix[i-1][w]);

           else
                 matrix[i][w] = matrix[i-1][w];

            pf("%d ", matrix[i][w]);
       }bl;
   }

   return matrix[n][W];
}


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
fli("knapsack.txt");
//flo();

    int n, w, price[200], weight[200];

    pf("Enter the number of goods: ");
    sfi(n);
    pf("Enter bag size: ");
    sfi(w);
    rep(i, 0, n){
        sfi2(weight[i], price[i]);
    }

    pf("Maximum Price: %d\n\n", knapSack(w, weight, price, n));


    return 0;
}

