#ifndef TIMER_H
#define TIMER_H

#include <time.h>

typedef struct TIMER
{
    clock_t start;
}TIMER_t;

void timer_start(TIMER_t * ths);
double timer_stop(TIMER_t * ths);

#endif // TIMER_H