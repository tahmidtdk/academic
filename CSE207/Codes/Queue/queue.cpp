#include<bits/stdc++.h>

#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pfc(i) printf("Case %d:\n", i)
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
using namespace std;






              // Code starts from here
struct node {
    int data;
    struct node *next;
}*NODE;


struct root{
    int cont;
    struct node *next;
    struct node *rear;
}*ROOT;

void create_head(){
    ROOT = (struct root*)malloc(sizeof(struct root));
    ROOT->cont=0;
    ROOT->next=NULL;
}

void create_node(){
    NODE=(struct node*)malloc(sizeof(node));
    NODE->data=NULL;
    NODE->next=NULL;
}


void insert_begin(int x){
    create_node();
    ROOT->cont++;
    NODE->data = x;
    ROOT->next=NODE;
    ROOT->rear=NODE;
}

void enqueue(int x){
    if(ROOT->cont>0){
        node *temp;
        temp=ROOT->next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        create_node();
        NODE->data=x;
        ROOT->rear=NODE;
        temp->next=NODE;
        ROOT->cont++;
    }else{
        insert_begin(x);
    }

}

void dequeue(){
    node *temp;
    temp=ROOT->next;
    ROOT->next=temp->next;
    free(temp);
    ROOT->cont--;
}

inline void front_rear(){
    pf("Front: %d  | Rear: %d\n", ROOT->next->data, ROOT->rear->data);
}


void display_list(){

    pf("Data: ");
    node *temp=ROOT->next;
    while(true){
        pf("%d ", temp->data);
        if(!temp->next) break;
        temp=temp->next;
    }bl;
}



int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    create_head();
    while(true){
        int key;
        system("cls");
        pf("1) Enqueue\n");
        pf("2) Dequeue\n");
        pf("3) Show Front & Rear\n");
        pf("4) Display all\n");
        pf("5) Exit\n");
        sfi(key);
        if(key==1){
            int num;
            sfi(num);
            enqueue(num);
        }else if(key==2){
            dequeue();
        }else if(key==3){
            int nn;
            front_rear();
            pf("Enter 0 to return\n");
            sfi(nn);
        }else if(key==4){
            display_list();
            int nn;
            pf("Enter 0 to return\n");
            sfi(nn);
        }else
            return 0;
    }
    return 0;
}
