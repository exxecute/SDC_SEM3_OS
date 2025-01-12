#include "timer.h"

void timer_start(TIMER_t * ths) 
{
    ths->start = clock();
}

double timer_stop(TIMER_t * ths) 
{
    clock_t __stop = clock();
    return (double)(__stop - ths->start) / CLOCKS_PER_SEC * 1000;
}