#include<bits/stdc++.h>

/*
    |------------------------------------------------------------------|
    |             Bismillah Hir Rahman Nir Raheem                      |
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

class Heap{
    int arr[200];
    int end_mark=0;
public:
     void _insert(int x){
        arr[end_mark]=x;
        int con_end = end_mark;
        while(true){
            double parent = (double)(con_end-1) / 2;
            if(parent <0) break;
            int ind=parent;
            if(arr[ind]< arr[con_end]) swap(arr[ind], arr[con_end]);
            con_end = ind;
        }
            end_mark++;
     }
     void _delete(){
        arr[0] = arr[end_mark-1];
        end_mark--;
        int mark=0;
        int l_ch, r_ch;
        while(true){
            l_ch = 2*mark + 1;
            r_ch = 2*mark + 2;
            if(arr[mark]<arr[l_ch] and l_ch< end_mark-1 and arr[l_ch]>arr[r_ch]) {
                    swap(arr[mark],arr[l_ch]);
                    mark = l_ch;
            }
            else if(arr[mark]<arr[r_ch] and r_ch< end_mark-1) {
                    swap(arr[mark],arr[r_ch]);
                    mark = r_ch;
            }
            else break;
        }
    }
     void display(){
         pf("Heaps Data: ");
        rep(i, 0, end_mark){
            pf("%d ", arr[i]);
        }bl;
    }

};


int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    int key, num, mar;
    Heap H1;
    while(true){
            bl;bl;bl;
        pf("\t1) Insert\n");
        pf("\t2) Delete\n");
        pf("\t3) Print\n");
        pf("\t0) Exit\n");
        sfi(key);
        if(key==1){
            sfi(num);
            H1._insert(num);
        }else if(key==2){
            H1._delete();
        }else if(key==3){
            H1.display();
            pf("Enter 0 to return");bl;
            sfi(mar);
        }else if(!key) break;
        system("cls");
    }
    return 0;
}
