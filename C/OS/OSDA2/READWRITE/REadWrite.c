#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
sem_t readMut, wrtMut;
pthread_t tid;
pthread_t writerthreads[100], readerthreads[100];
int readercount;

void *reader(void *param) {
  sem_wait(&readMut);
  readercount++;
  if (readercount == 1)
    sem_wait(&wrtMut);
  sem_post(&readMut);
  printf("Reader %d is inside\n", readercount);
  // READ
  sem_wait(&readMut);
  readercount--;
  if (readercount == 0) {
    sem_post(&wrtMut);
  }
  sem_post(&readMut);
  printf("Reader %d is leaving\n", readercount + 1);
  return NULL;
}

void *writer(void *param) {
  puts("Writer is trying to enter");
  sem_wait(&wrtMut);
  puts("Writer has entered");
  // DO WRITE
  sem_post(&wrtMut);
  puts("Writer is leaving");
  return NULL;
}

int main() {
  int Readernumber, i;
  printf("Enter the number of readers: ");
  scanf("%d", &Readernumber);
  if (Readernumber > 100)
    Readernumber = 100;
  putchar('\n');
  int n1[Readernumber];
  sem_init(&readMut, 0, 1);
  sem_init(&wrtMut, 0, 1);
  for (i = 0; i < Readernumber; i++) {
    pthread_create(&writerthreads[i], NULL, reader, NULL);
    pthread_create(&readerthreads[i], NULL, writer, NULL);
  }
  for (i = 0; i < Readernumber; i++) {
    pthread_join(writerthreads[i], NULL);
    pthread_join(readerthreads[i], NULL);
  }
}
