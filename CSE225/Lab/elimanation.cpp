#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |                                                                  |
    |           ░█▀▀▀█ ░█─░█ ─█▀▀█ ░█──░█ ░█─▄▀ ░█─░█                  |
    |           ─▀▀▀▄▄ ░█▀▀█ ░█▄▄█ ░█▄▄▄█ ░█▀▄─ ░█▀▀█                  |
    |           ░█▄▄▄█ ░█─░█ ░█─░█ ──░█── ░█─░█ ░█─░█                  |
    |                                                                  |
    |                                          Country:Bangladesh/EWU  |
    |                                          Problem:                |
    |------------------------------------------------------------------|
*/

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
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
using namespace std;

// Shaykh Siddique

double matrix[5][5];

void print_matrix(int n)
{
    bl;bl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        bl;
    }
}

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//    fli();
    int n;
    cout<<"How Many Equation Do you have: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            sfd(matrix[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        int maxEl=fabs(matrix[i][i]);
        int maxRow=i;
        for(int k=i+1; k<=n; k++){
            if(matrix[k][i]>maxEl){
                maxEl=matrix[k][i];
                maxRow=k;
            }
        }
//        for(int k=i; k<=n+1; k++){
//            double tmp = matrix[maxRow][k];
//            matrix[maxRow][k] = matrix[i][k];
//            matrix[i][k] = tmp;
//        }

         for (int k=i+1; k<=n; k++) {
            double c = matrix[k][i]/matrix[i][i];

            for (int j=i; j<=n+1; j++) {
                if (i==j) {
                    matrix[k][j] = 0;
                }else {
                    matrix[k][j] -= c * matrix[i][j];
                }
            }
        }

        for(int k=i+1; k<=n; k++){
            double u=matrix[k][i]/matrix[i][i];
            for(int j=i+1; j<=n+1; j++){
                matrix[k][j]=matrix[k][j]-(u*matrix[i][j]);
            }
        }
        print_matrix(n);
    }

    map<int, double>x;
         x[n]=matrix[n][n+1]/matrix[n][n];

    for(int i=n-1; i>=1; i--){
        double sum=0;
        for(int j=i+1; j<=n; j++){
            sum+=(matrix[i][j]*x[j]);
        }
        x[i]=(matrix[i][n+1]-sum)/matrix[i][i];
    }
    bl;bl;
    for(int i=1; i<=n; i++){
        cout<<"X"<<i<<" : "<<x[i]<<endl;
    }


    return 0;
}
