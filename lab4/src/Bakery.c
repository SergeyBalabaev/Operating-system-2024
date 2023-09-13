#include "Bakery.h"

bakery_mutex B_M;

#define N_threads 2

void bakery_mutex_init()
{
    B_M.lock = lock;
    B_M.unlock = unlock;
    for (int i = 0; i < N_threads; i++)
    {
        B_M.ticket[i] = 0;
        B_M.choosing[i] = 0;
    }
}

void lock(int i)
{
    B_M.choosing[i] = 1;
    B_M.ticket[i] = max(B_M.ticket[0], B_M.ticket[1]) + 1;
    B_M.choosing[i] = 0;
    for (int j = 0; j < N_threads; j++)
    {
        while (B_M.choosing[j])
            continue;
        while (B_M.ticket[j] && ((B_M.ticket[j], j) < (B_M.ticket[i], i)))
            continue;
    }
}

void unlock(int i)
{
    B_M.ticket[i] = 0;
}