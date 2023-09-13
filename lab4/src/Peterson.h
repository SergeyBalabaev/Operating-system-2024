#pragma once

typedef struct peterson_mutex
{
    _Atomic int flag[2];
    _Atomic int turn;
    void (*lock)(int i);
    void (*unlock)(int i);
} peterson_mutex;

void peterson_mutex_init();
static void lock(int);
static void unlock(int);