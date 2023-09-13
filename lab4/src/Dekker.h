#pragma once

typedef struct deccer_mutex
{
    //_Atomic int flag[2];
    //_Atomic int turn;
    int flag[2];
    int turn;
    void (*lock)(int i);
    void (*unlock)(int i);
} deccer_mutex;

void deccer_mutex_init();
static void lock(int);
static void unlock(int);