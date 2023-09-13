#include "Dekker.h"

deccer_mutex D_M;

void deccer_mutex_init()
{
    D_M.lock = lock;
    D_M.unlock = unlock;
    D_M.turn = 0;
    D_M.flag[0] = 1;
    D_M.flag[1] = 1;
}

void lock(int i)
{
    int j = 1 - i;
    while (D_M.flag[j] == 1)
    {
        if (D_M.turn == j)
        {
            D_M.flag[i] = 0;
            while (D_M.turn == j)
                continue;
            D_M.flag[i] = 1;
        }
    }
}

void unlock(int i)
{
    D_M.turn = 1 - i;
    D_M.flag[i] = 0;
}