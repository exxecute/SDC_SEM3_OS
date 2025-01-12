/**
 * @file main.c
 * 
 * @author Uladzislau Mikhayevich
 * 
 * @brief Variant 7
 */

#include "src/memory_controller/memory_controller.h"

#include "string.h"

int main(void) {
    uint8_t * array = (uint8_t*)malloc(500);

    memory_controller_t controller;
    memory_controller_ctr(controller);

    printf("Create array\n");
    memory_controller_print(controller);

    printf("\nPush 10 elements\n");
    for (int i = 0; i < 10; i++) {
        memory_controller_push(controller, i);
    }
    memory_controller_print(controller);

    printf("\nPush array 500Byte\n");
    memory_controller_push_array(controller, array, 10);
    memory_controller_print(controller);

    printf("\nPush array with increasing memory 500Byte\n");
    memory_controller_push_array(controller, array, 500);
    memory_controller_print(controller);

    printf("\nFlush\n");
    memory_controller_flush(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);

    array = (uint8_t*)realloc(array, 1000);

    printf("\nPush array 1Kbyte\n");
    memory_controller_push_array(controller, array, 1000);
    memory_controller_print(controller);

    memory_controller_flush(controller);
    printf("\nPush array with increasing memory 1Kbyte\n");
    memory_controller_push_array(controller, array, 1000);
    memory_controller_print(controller);

    array = (uint8_t*)realloc(array, 2000);


    printf("\nFlush\n");
    memory_controller_flush(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);
    memory_controller_multiply_2(controller);

    printf("\nPush array 2Kbyte\n");
    memory_controller_push_array(controller, array, 2000);
    memory_controller_print(controller);

    memory_controller_flush(controller);

    printf("\nPush array with increasing memory 2Kbyte\n");
    memory_controller_push_array(controller, array, 2000);
    memory_controller_print(controller);

    printf("\nFlush\n");
    memory_controller_flush(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);
    memory_controller_multiply_2(controller);
    memory_controller_multiply_2(controller);

    printf("\nPush array 4Kbyte\n");
    memory_controller_push_array(controller, array, 4000);
    memory_controller_print(controller);

    memory_controller_flush(controller);
    array = (uint8_t*)realloc(array, 4000);

    printf("\nPush array with increasing memory 4Kbyte\n");
    memory_controller_push_array(controller, array, 4000);
    memory_controller_print(controller);

    printf("\nFlush\n");
    memory_controller_flush(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);
    memory_controller_multiply_2(controller);
    memory_controller_multiply_2(controller);

    printf("\nPush array 8Kbyte\n");
    memory_controller_push_array(controller, array, 8000);
    memory_controller_print(controller);

    memory_controller_dtr(controller);
    
    return 0;
}