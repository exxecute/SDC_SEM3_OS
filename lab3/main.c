/**
 * @file main.c
 * 
 * @author Uladzislau Mikhayevich
 * 
 * @brief Variant 7
 */

#include "src/memory_controller/memory_controller.h"
#include "src/timer/timer.h"

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

int main(void) {
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

        printf("\nIncrease to %d Byte\n", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_increase_to(controller, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("\nPush array %d Byte\n", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_push_array(controller, array, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("\nPush array with increasing memory %d Byte\n", memory_sizes_test[i]);
        timer_start(&timer);
        memory_controller_push_array(controller, array, memory_sizes_test[i]);
        printf("Time: %f\n", timer_stop(&timer));
        memory_controller_print(controller);

        printf("\nFlush\n");
        memory_controller_flush(controller);
        memory_controller_print(controller);
    }

    memory_controller_dtr(controller);
    free(array);
    
    return 0;
}