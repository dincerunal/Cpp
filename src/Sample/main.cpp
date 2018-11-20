#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct tagPARAM {
	char name[100];
	int min, max, count;
} PARAM;

void *thread_proc(void *param);

unsigned int g_seed;

int main(void)
{
	pthread_t tid1, tid2;
	int result;
	PARAM p1 = { "t1", 10, 20, 10000 };
	PARAM p2 = { "t2", 10, 20, 10000 };
	void *ret_val1, *ret_val2;

	g_seed = (unsigned int)time(NULL);

	if ((result = pthread_create(&tid1, NULL, thread_proc, (void *)&p1)) != 0) {
		fprintf(stderr, "pthread_create: %s\n", strerror(result));
		exit(EXIT_FAILURE);
	}

	if ((result = pthread_create(&tid2, NULL, thread_proc, (void *)&p2)) != 0) {
		fprintf(stderr, "pthread_create: %s\n", strerror(result));
		exit(EXIT_FAILURE);
	}

	pthread_join(tid1, &ret_val1);
	pthread_join(tid2, &ret_val2);

	printf("Result1:%d\n", (int)(intptr_t)ret_val1);
	printf("Result2:%d\n", (int)(intptr_t)ret_val2);

	return 0;
}

void *thread_proc(void *param)
{
	PARAM *p = (PARAM *)param;
	int min, max, count;
	char name[100];
	int i;
	int sum;

	min = p->min;
	max = p->max;
	count = p->count;
	strcpy(name, p->name);

	sum = 0;
	while (count--) {
		int val = rand_r(&g_seed) % (max - min) + min;
		sum += val;
	}

	return (void *)(intptr_t)sum;
}

