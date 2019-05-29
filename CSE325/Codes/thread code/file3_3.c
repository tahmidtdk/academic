#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
//custom hashdefines

#define pf printf
#define sf scanf

int glob_data = 10;


void *kidfunc_1(void *p){
	int local_data = 30;
	pthread_t tid;
	tid = pthread_self();
	glob_data = 15;
	pf("kid_thread_1 thread id is ---> %lu\n", tid);
	pf("kid_thread_1 global variable value: %d\n", glob_data);
	pf("kid_thread_1 local variable value: %d\n", local_data);
	pthread_exit(0);
}


void *kidfunc_2(void *p){
	int local_data = 35;
	pthread_t tid; 
        tid = pthread_self();
	glob_data =15;
	pf("Kid_thread_2 thread id is ---> %lu\n", tid);
	pf("kid_thread_2 global variable value: %d\n", glob_data);
	pf("kid_thread_2 local variable value: %d\n", local_data);
	exit(0);
}

int main(int args, char* arg[]){
    int local_data = 40;
    pthread_t kid1, kid2;
    pthread_create(&kid1, NULL, kidfunc_1, NULL);
    pthread_create(&kid2, NULL, kidfunc_2, NULL);
    pf("Parent process id is ---> %d\n", getpid());
    pf("Main thread global variable value: %d\n", glob_data);
    pf("Main Thread local variable value: %d\n", local_data);
    pthread_join(kid1, NULL);
    pthread_join(kid2, NULL);
    pf("No more kid!!\n");
	return 0;
}
