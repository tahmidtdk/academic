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

struct node{
    int data;
    struct node *next;
}*NODE;


struct root{
    int cont;
    struct node *next;
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
    NODE->next=ROOT->next;
    ROOT->next=NODE;
}

void push(int x){
    if(ROOT->cont<1){
        insert_begin(x);
        return;
    }
    node *temp;
    temp=ROOT->next;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    create_node();
    NODE->data=x;
    temp->next=NODE;
    ROOT->cont++;

}

void pop(){
    node *temp;
    temp=ROOT->next;
    while(temp->next->next){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    ROOT->cont--;
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
    create_head();
    push(5);
    push(15);
    push(25);
    pop();
    display_list();
    return 0;
}
