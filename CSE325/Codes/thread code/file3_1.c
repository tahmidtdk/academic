#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
//custom hashdefines

#define pf printf
#define sf scanf


void *kidfunc(void *p){
	pf("kid process id is ---> %d\n", getpid());
}


int main(int args, char* arg[]){
    pthread_t kid;
    pthread_create(&kid, NULL, kidfunc, NULL);
    pf("Parent process id is ---> %d\n", getpid());
    pthread_join(kid, NULL);
    pf("No more kid!!\n");
	return 0;
}
