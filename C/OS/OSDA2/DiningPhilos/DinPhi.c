#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_FORKS 5

enum State { THINKING, EATING, EATEN };

pthread_mutex_t forks[NUM_FORKS];
pthread_t philosophers[NUM_PHILOSOPHERS];
enum State state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
  int id = *(int *)arg;
  int left_fork = id;
  int right_fork = (id + 1) % NUM_FORKS;
  int n = 3;

  while (n) {
    // Think
    printf("Philosopher %d is thinking...\n", id + 1);

    // Pick up forks
    if (state[(id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] == EATING ||
        state[(id + 1) % NUM_PHILOSOPHERS] == EATING) {
      sleep(1);
      continue;
    }

    n--;
    state[id] = EATING;
    pthread_mutex_lock(&forks[left_fork]);
    pthread_mutex_lock(&forks[right_fork]);

    // Eat
    printf("Philosopher %d is eating!\n", id + 1);

    // Put down forks
    pthread_mutex_unlock(&forks[left_fork]);
    pthread_mutex_unlock(&forks[right_fork]);
    state[id] = THINKING;
  }
  return NULL;
}

int main() {
  int i;
  assert(NUM_FORKS >= NUM_PHILOSOPHERS);
  for (i = 0; i < NUM_FORKS; ++i) {
    pthread_mutex_init(&forks[i], NULL);
  }
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    int *id = (int *)malloc(sizeof(int));
    *id = i;
    pthread_create(&philosophers[i], NULL, philosopher, id);
    state[i] = THINKING;
  }

  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }

  for (i = 0; i < NUM_FORKS; i++) {
    pthread_mutex_destroy(&forks[i]);
  }

  return 0;
}
