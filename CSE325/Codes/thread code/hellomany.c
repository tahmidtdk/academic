#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
//custom hashdefines
#define N 100
#define pf printf
#define sf scanf


void *kidfunc(void *p){
	pf("kid thread id is ---> %lu\n", pthread_self());
}


int main(int args, char* arg[]){
    pthread_t kid[N];
    int n;
    pf("Enter Number of threads: ");
    sf("%d", &n);

    for(int i=0; i<n; i++){
    	pthread_create(&kid[i], NULL, kidfunc, &i);
	if(i%4==0) sleep(1);
    }
    pf("Parent process id is ---> %d\n", getpid());
    for(int i=0; i<n; i++){
    	pthread_join(kid[i], NULL);
    }
    pf("No more kid!!\n");
	return 0;
}
