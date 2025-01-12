/**
 * @file main.c
 * 
 * @author Uladzislau Mikhayevich
 * 
 * @brief Variant 7
 */

#include "src/memory_controller/memory_controller.h"

int main(void) {
    memory_controller_t controller;
    memory_controller_ctr(controller);
    memory_controller_print(controller);
    memory_controller_multiply_2(controller);
    memory_controller_print(controller);
    memory_controller_push(controller, 1);
    memory_controller_print(controller);
    uint8_t array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    memory_controller_push_array(controller, &array, 10);
    // memory_controller_print(controller);
    // memory_controller_dtr(controller);
    return 0;
}