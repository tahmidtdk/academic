#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#define N 10

int buffer[10];
int in =0;
int out =0;

sem_t mutex, empty, full;

void delay(){
	srand(time(NULL));
	int k = (rand()%5)+1;
	sleep(k);
}

int produce_item(){
	srand(time(NULL));
	int r=rand();
	delay(); //make some delay before printing
	printf("%d is produced by %u\n", r, pthread_self());
	return r;
}


void consumer_item(int item){
	delay();//make some delay before printing
	printf("%d is consumed by %u\n", item, pthread_self());
}


void insert_item(int item){
	buffer[in] = item;
	in = (in+1)%N;
	printf("%d is inserted by %u\n", item, pthread_self());
}

int remove_item(){
	int item = buffer[out];
	out = (out+1)%N;
	printf("%d is removed by %u\n", item, pthread_self());
	return item;
}



void producer(){
	int item;
	while(1){
		item = produce_item();
		sem_wait(&empty); //down semaphore
		sem_wait(&mutex); //down semaphore
		insert_item(item);
		sem_post(&mutex); //up semaphore
		sem_post(&full); //up semaphore
	}

}


void consumer(){
	int item;
	while(1){
		sem_wait(&full); //down semaphore
		sem_wait(&mutex); //down semaphore
		item = remove_item();

		sem_post(&mutex); //up semaphore
		sem_post(&empty); //up semaphore
		consumer_item(item);
	}
}


int main(){
	pthread_t prod, cons;

	if(sem_init(&mutex, 0, 1) == -1){
		perror("Could not initialize mylock semaphore");
		exit(2);
	}
	if(sem_init(&empty, 0, N) == -1){
		perror("Could not initialize mylock semaphore");
		exit(2);
	}
	if(sem_init(&full, 0, 0) == -1){
		perror("Could not initialize mylock semaphore");
		exit(2);
	}
//thread of producer
	if(pthread_create(&prod, NULL, producer, NULL)<0){
		perror("Error: thread cannot be created");
	}
//thread of consumer
	if(pthread_create(&cons, NULL, consumer, NULL)<0){
		perror("Error: thread cannot be created");
	}

pthread_join(prod, NULL);
pthread_join(cons, NULL);
sem_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);

return 0;
}
