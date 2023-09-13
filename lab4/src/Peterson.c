#include "Peterson.h"

peterson_mutex P_M;

void peterson_mutex_init()
{
    P_M.lock = lock;
    P_M.unlock = unlock;
    P_M.turn = 0;
    P_M.flag[0] = 1;
    P_M.flag[1] = 1;
}

void lock(int i)
{
    int j = 1 - i;
    P_M.flag[i] = 1;
    P_M.turn = j;
    while (P_M.flag[j] && P_M.turn == j)
        continue;
}

void unlock(int i)
{
    P_M.flag[i] = 0;
}