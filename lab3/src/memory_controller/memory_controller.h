#ifndef MEMORY_CONTROLLER_H
#define MEMORY_CONTROLLER_H

#include <stdint.h>

#define FLAG_PRINT_ARRAY        0

typedef struct memory_controller_data_t* memory_controller_t;

typedef enum memory_controller_error
{
    OK = 0,
    ERROR
}memory_controller_error_e;

void memory_controller_ctr(memory_controller_t controller);
void memory_controller_ctr_size(memory_controller_t controller, int size);
void memory_controller_dtr(memory_controller_t controller);
void memory_controller_print(memory_controller_t controller);
memory_controller_error_e memory_controller_multiply(memory_controller_t controller, int value);
memory_controller_error_e memory_controller_decrese(memory_controller_t controller, int value);
memory_controller_error_e memory_controller_push_controller_array(memory_controller_t dst, memory_controller_t src, int size);
memory_controller_error_e memory_controller_multiply_default(memory_controller_t controller);
memory_controller_error_e memory_controller_push(memory_controller_t controller, uint8_t value);
memory_controller_error_e memory_controller_push_array(memory_controller_t controller, uint8_t* array, int size);
memory_controller_error_e memory_controller_push_array_by_blocks(memory_controller_t controller, uint8_t* array, int size, int block_size);
memory_controller_error_e memory_controller_push_array_by_blocks_default(memory_controller_t controller, uint8_t* array, int size)
void memory_controller_flush(memory_controller_t controller);
memory_controller_error_e memory_controller_increase_to(memory_controller_t controller, int size);
int memory_controller_get_capacity(memory_controller_t controller);
memory_controller_error_e memory_controller_push_controller_array_block(memory_controller_t dst, memory_controller_t src, int size, int block_size);

#endif // MEMORY_CONTROLLER_H