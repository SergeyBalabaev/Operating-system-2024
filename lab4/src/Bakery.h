#pragma once

#define max(a,b) (((a) > (b)) ? (a) : (b))
typedef struct bakery_mutex
{
    _Atomic int ticket[2];
    _Atomic int choosing[2];
    void (*lock)(int i);
    void (*unlock)(int i);
} bakery_mutex;

void bakery_mutex_init();
static void lock(int);
static void unlock(int);