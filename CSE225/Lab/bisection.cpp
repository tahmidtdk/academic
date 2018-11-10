#include<bits/stdc++.h>
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
#define bug puts("I am here")
#define loope(n, test) for(int i=n; i<=test; i++)
#define loop(n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
//#define fx(v, a, b, c) (a*pow(v, 2))-(b*v)-c
using namespace std;

              // Shaykh Siddique
double func(double x, double a, double b, double c){
    double k=(a*(x*x))+(b*x)+c;
    return k;

}

struct id{
    double r1, r2;
    id(double x, double y){
        r1=x;
        r2=y;
    }
};

bool check_diff(double num){

    if(num>0){
        if(num<EPS) return true;
    }
    return false;
}

id range_check(double an, double an1, double an2){
    double r=sqrt(pow((an1/an),2)-(2*(an2/an)));
    r=fabs(r);
    double pev, nex, id1, id2;
    for(int i=r; i>=((-1)*r); i--){
        if(i==r){
            pev=func(i,an, an1, an2);
            id1=i;
        }
        else{
            nex=func(i,an, an1, an2);
            id2=i;
            if(pev*nex<0){
                break;
            }
            pev=nex;
            id1=i;
        }
    }
    return id(min(id1, id2), max(id1, id2));
}



int main(){
//fli();
    double x1, x2, mid, fx1, fx2, fxm, ans;
    double a, b, c;
    sfd2(a, b); sfd(c);
    id range=range_check(a, b, c);
    x1=range.r1;
    x2=range.r2;

//    debug(x1);
//    debug(x2);
    while(true){
        mid=(x1+x2)/2;
        fx1=func(x1, a, b, c);
        fx2=func(x2, a, b, c);
        fxm=func(mid, a, b, c);
        ans=mid;

        if(check_diff(fxm)){
            ans=mid;
            break;
        }
        if(fxm*fx1<0){
            x2=mid;
        }else if(fxm*fx2<0){
            x1=mid;
        }
    }
    cout<<ans<<endl;
    return 0;
}
