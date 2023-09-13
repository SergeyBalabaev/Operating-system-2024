// gcc mutex.c deccer.c -o mutex -lpthread -fsanitize=thread
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include "Dekker.h"
#include "Peterson.h"
#include "Bakery.h"

extern deccer_mutex D_M;
extern peterson_mutex P_M;
extern bakery_mutex B_M;

int Global = 0;
void *Thread(void *_args) {
  int arg = (uintptr_t)_args;
  //lock(arg);
  Global++;
  //unlock(arg);
}

int main() {
  pthread_t t1,t2;
  deccer_mutex_init();
  pthread_create(&t1, NULL, Thread, (void *)0);
  pthread_create(&t2, NULL, Thread, (void *)1);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  printf("%d\n",Global);
  return Global;
}
