//  gcc deadlock2.c -o deadlock2 -lpthread -fsanitize=thread
//  TSAN_OPTIONS=detect_deadlocks=1:second_deadlock_stack=1 ./deadlock

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
static int global_var = 0;
void *function1();
pthread_mutex_t mutex; 

int main()
{
  
    pthread_mutex_init(&mutex, NULL); // initialize the lock
    pthread_t one, two;
    pthread_create(&one, NULL, function1, NULL); // create thread
    pthread_join(one, NULL);
    printf("Global var = %d\n", global_var);
    return 0;
}

void summ_f()
{
    pthread_mutex_lock(&mutex);
    if(global_var!=5)
        {
            global_var++;
            summ_f();
        }
    pthread_mutex_unlock(&mutex);
}

void *function1()
{
    summ_f();
}


/*
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
static int global_var = 0;
void *function1();
pthread_mutex_t mutex; // mutex lock
pthread_mutexattr_t Attr;

int main()
{
    pthread_mutexattr_init(&Attr);
    pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &Attr);
    
    //pthread_mutex_init(&mutex, NULL); // initialize the lock
    pthread_t one, two;
    pthread_create(&one, NULL, function1, NULL); // create thread
    pthread_join(one, NULL);
    printf("Global var = %d\n", global_var);
    return 0;
}

void summ_f()
{
    pthread_mutex_lock(&mutex);
    if(global_var!=5)
        {
            global_var++;
            summ_f();
        }
    pthread_mutex_unlock(&mutex);
}

void *function1()
{
    summ_f();
}*/