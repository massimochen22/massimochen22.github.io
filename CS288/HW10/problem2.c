#include<stdio.h>
#include<pthread.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_THREADS 4

typedef struct {
	int nrank;
    double sum;
} thread_data;

thread_data td[NUM_THREADS];

void* helper(void *nrank) {
	int thread_rank = *(int *)nrank;
	double incr = 0;
	int sign;
    int k = thread_rank;

	if (k % 2) {
		sign = -1;
	} else {
		sign = 1;
	}

	td[thread_rank].sum = 4*((double)sign / (2 * thread_rank + 1));

	do {
		k += NUM_THREADS;

		if (k % 2) {
			sign = -1;
		} else {
			sign = 1;
		}

		incr = (double)sign / (2 * k + 1);
		td[thread_rank].sum += 4 * incr;
	}
  while ( fabs(incr) > 1e-6);

	return NULL;
}

int main(){
	int nrank = 0;
	int err;
	double pi = 0;
	pthread_t thread_ids[NUM_THREADS];

	while(nrank < NUM_THREADS) {
		td[nrank].nrank = nrank;

		err = pthread_create(&(thread_ids[nrank]), NULL, helper, (void*)&td[nrank].nrank);
		if (err != 0) {
			return 1;
		}
		nrank++;
	}

	nrank = 0;
	while(nrank < NUM_THREADS) {
		pthread_join(thread_ids[nrank], NULL);
		nrank++;
	}

	nrank = 0;
	while(nrank < NUM_THREADS) {
        pi += td[nrank].sum;
		nrank++;
	}


  printf("%f\n",pi);

  return 0;
}