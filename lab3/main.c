/**
 * @file main.c
 * 
 * @author Uladzislau Mikhayevich
 * 
 * @brief Variant 7
 */

#include "src/memory_controller/memory_controller.h"
#include "src/timer/timer.h"

#include <stdlib.h>
#include <stdio.h>

#define EASY_TASK   1
#define HARD_TASK   0


#if EASY_TASK == 1
void easy_task(void)
{
    TIMER_t timer;

    memory_controller_t controller_A;
    int a_size = 100000;
    memory_controller_t controller_B;
    int b_size = 100000;

    memory_controller_ctr_size(controller_A, a_size);
    memory_controller_ctr_size(controller_B, b_size);

    timer_start(&timer);
    memory_controller_multiply(controller_B, 2);
    printf("Multiply B Time: %f\n", timer_stop(&timer));

    timer_start(&timer);
    memory_controller_multiply(controller_A, 2);
    printf("Multiply A Time: %f\n", timer_stop(&timer));

    int start_position = 2;
    int length = 10;

    memory_controller_increase_to(controller_A, memory_controller_get_capacity(controller_A) + length);
    timer_start(&timer);
    memory_controller_push_controller_array(controller_A, controller_B, length);
    printf("Push controller array Time: %f\n", timer_stop(&timer));

    memory_controller_decrese(controller_A, 2);
    memory_controller_decrese(controller_B, 2);

    memory_controller_dtr(controller_A);
    memory_controller_dtr(controller_B);
}
#endif // EASY_TASK

#if HARD_TASK == 1
static const int memory_sizes_test[] =
{
    500,
    1000,
    2000,
    8000,
    16000,
    32000,
    64000,
    128000,
    256000,
    512000,
    1024000,
    2048000,
    4096000,
    8192000,
    16384000,
    32768000,
    50000000,
};

void hard_task(void)
{
    uint8_t * array = (uint8_t*)malloc(500);

    memory_controller_t controller;
    memory_controller_ctr(controller);

    TIMER_t timer;

    printf("Create array\n");
    memory_controller_print(controller);

    printf("\nPush 10 elements\n");
    timer_start(&timer);
    for (int i = 0; i < 10; i++) {
        memory_controller_push(controller, i);
    }
    printf("Time: %f\n", timer_stop(&timer));
    memory_controller_print(controller);

    for(int i = 0; i < 17; i++)
    {
        array = (uint8_t*)realloc(array, memory_sizes_test[i]);

        printf("Increase to %d Byte ", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_increase_to(controller, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("Push array %d Byte ", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_push_array_by_blocks(controller, array, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("Push array with increasing memory %d Byte ", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_push_array_by_blocks(controller, array, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("\nFlush\n");
        memory_controller_flush(controller);
        memory_controller_print(controller);
    }

    memory_controller_dtr(controller);
    free(array);
}
#endif // HARD_TASK

int main(void) {
#if EASY_TASK == 1
    easy_task();
#endif // EASY_TASK
#if HARD_TASK == 1
    hard_task();
#endif // HARD_TASK
    
    return 0;
}