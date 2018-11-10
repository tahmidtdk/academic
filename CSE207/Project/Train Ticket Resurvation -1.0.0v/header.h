#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
//    Custom hash define
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
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << " : " << x << endl
#define fi first
#define se second
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)

//        Custom data define
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
#define default_value NULL
const long long inf = 1000000000LL;
using namespace std;



//    global variables
string userna_global="Not logged in...";  /// global variable

class User{
public:
    string user_name, user_id, user_pass;
};


struct Train{
    string t_name, t_id;
    int fares;
    int t_seats, t_numOfStaions;
    map<string, string>t_time_mp;
    vector<string>t_stations;
    Train(string t_n, string t_i, int t_se, int t_numOfStaions, int fares ,vector<string>t_sta, map<string, string>t_mp){
        t_name = t_n;
        t_id = t_i;
        t_seats = t_se;
        t_stations = t_sta;
        t_time_mp=t_mp;
    }
    Train(){
        //empty construction
    }

};

