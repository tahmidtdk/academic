#include<bits/stdc++.h>

/*
    |--------------------------------------------------------------|
    |                                                              |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█              |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█              |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█              |
    |                                                              |
    |                                          Country:Bangladesh  |
    |                                          Problem:            |
    |--------------------------------------------------------------|
*/
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
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
#define find puts("I am here")
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 0.01
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

              // Shaykh Siddique
double fx(double x){
    double r= pow(x, 4) - x - 10;
    return r;
}

double x3_ans(double x1, double x2){
    cout<<"x3 = "<<x2<<" - ( "<<fx(x2)<<" * "<<(x2-x1)<<") / ("<<fx(x2)<<" - "<<fx(x1)<<" )"<<endl;
    double x3=(fx(x2)*(x2-x1))/(fx(x2)-fx(x1));
    x3=x2-x3;
    return x3;
}

int main(){
//fli();
    double x1, x2, x3, k;
    sfd2(x1, x2);
    while(true){
        x3=x3_ans(x1, x2);
        bl;
        cout<<x3<<endl;
        bl;

        double check=x3-x2;
        debug(x3-x2);
        if(check>0 and check<EPS) break;
        x1=x2;
        x2=x3;
        debug(x1);
        debug(x2);
        cin>>k;
    }
    cout<<x3<<endl;
    return 0;
}
