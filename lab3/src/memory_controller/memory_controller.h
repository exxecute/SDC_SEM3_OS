#ifndef MEMORY_CONTROLLER_H
#define MEMORY_CONTROLLER_H

#include <stdint.h>

typedef struct memory_controller_data_t* memory_controller_t;

typedef enum memory_controller_error
{
    OK = 0,
    ERROR
}memory_controller_error_e;

void memory_controller_ctr(memory_controller_t controller);
void memory_controller_dtr(memory_controller_t controller);
void memory_controller_print(memory_controller_t controller);
memory_controller_error_e memory_controller_multiply(memory_controller_t controller, int value);
memory_controller_error_e memory_controller_multiply_2(memory_controller_t controller);
memory_controller_error_e memory_controller_push(memory_controller_t controller, uint8_t value);
memory_controller_error_e memory_controller_push_array(memory_controller_t controller, uint8_t* array, int size);
void memory_controller_flush(memory_controller_t controller);
memory_controller_error_e memory_controller_increase_to(memory_controller_t controller, int size);

#endif // MEMORY_CONTROLLER_H