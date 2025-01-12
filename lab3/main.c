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
    uint8_t * array = (uint8_t*)malloc(10);
    // uint8_t array2[5] = {0, 1, 2, 3, 4};
    // memcpy(array + 5, array2, 5);
    memory_controller_t controller;
    memory_controller_ctr(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);
    memory_controller_print(controller);
    memory_controller_push(controller, 1);
    memory_controller_push(controller, 2);
    memory_controller_push(controller, 1);
    memory_controller_print(controller);
    memory_controller_push_array(controller, array, 10);
    memory_controller_print(controller);
    memory_controller_dtr(controller);
    return 0;
}