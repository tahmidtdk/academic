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

class Queue {

    struct node {
    int data;
    struct node *next;
    }*NODE;

    struct root{
        int cont;
        struct node *next;
        struct node *rear;
    }*ROOT;

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

public:
    Queue(){
        //constructor
        ROOT = (struct root*)malloc(sizeof(struct root));
        ROOT->cont=0;
        ROOT->next=NULL;
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

    int Front(){
        return ROOT->next->data;
    }
    int Rear(){
        return ROOT->rear->data;
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

    bool emp(){
        if(!ROOT->cont) return true;
        return false;
    }
};



int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//fli();
//flo();
    Queue q1, q2, q3;
    q1.enqueue(5);
    q1.enqueue(7);
    q1.enqueue(9);
    q1.enqueue(2);

    q1.display_list();

    q2.enqueue(4);
    q2.enqueue(15);
    q2.enqueue(17);
    q2.enqueue(24);

    q2.display_list();
//    q2.display_list();


    while(!q1.emp()){
         int xx= q1.Front();
         q1.dequeue();
         q3.enqueue(xx);
    }
    while(!q2.emp()){
         int xx= q2.Front();
         q2.dequeue();
         q3.enqueue(xx);
    }

    q3.display_list();
    return 0;
}
