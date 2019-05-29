#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
//custom hashdefines

#define pf printf
#define sf scanf


void *kidfunc_1(void *p){
	pthread_t tid;
	tid = pthread_self();
	pf("kid_thread_1 thread id is ---> %lu\n", tid);
}


void *kidfunc_2(void *p){
	pthread_t tid;
        tid = pthread_self();
	pf("Kid_thread_2 thread id is ---> %lu\n", tid);
}

int main(int args, char* arg[]){
    pthread_t kid1, kid2;
    pthread_create(&kid1, NULL, kidfunc_1, NULL);
    pthread_create(&kid2, NULL, kidfunc_2, NULL);
    pf("Parent process id is ---> %d\n", getpid());
    pthread_join(kid1, NULL);
    pthread_join(kid2, NULL);
    pf("No more kid!!\n");
	return 0;
}
