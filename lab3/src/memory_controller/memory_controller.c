#include "memory_controller.h"
#include <string.h>

#define START_CAPACITY_BYTES 500
#define MAX_CAPACITY_BYTES 50000

typedef struct memory_controller_data
{
    uint8_t* array;
    int size;
    int capacity;
}memory_controller_data_t;

#define CONVERT_POINTER(pointer) ((memory_controller_data_t*)pointer)

void memory_controller_ctr(memory_controller_t controller)
{
    memory_controller_data_t* ths = (memory_controller_data_t*)controller;
    ths->size = 0;
    ths->array = (uint8_t*)malloc(START_CAPACITY_BYTES);
    ths->capacity = START_CAPACITY_BYTES;
    ths->size = 0;
}

void memory_controller_dtr(memory_controller_t controller)
{
    memory_controller_data_t* ths = CONVERT_POINTER(controller);
    free(ths->array);
}

void memory_controller_print(memory_controller_t controller)
{
    memory_controller_data_t* ths = CONVERT_POINTER(controller);
    printf("Memory controller:\n");
    printf("Capacity: %d\n", ths->capacity);
    printf("Size: %d\n", ths->size);
    printf("Array: ");
    for (int i = 0; i < ths->size; i++) {
        printf("%d ", ths->array[i]);
    }
    printf("\n");
}

memory_controller_error_e memory_controller_multiply_2(memory_controller_t controller)
{
    memory_controller_data_t* ths = CONVERT_POINTER(controller);
    if(ths->capacity >= MAX_CAPACITY_BYTES) return ERROR;
    ths->capacity *= 2;
    if(ths->capacity > MAX_CAPACITY_BYTES) ths->capacity = MAX_CAPACITY_BYTES;
    ths->array = (uint8_t*)realloc(ths->array, ths->capacity);
}

memory_controller_error_e memory_controller_push(memory_controller_t controller, uint8_t value)
{
    memory_controller_data_t* ths = CONVERT_POINTER(controller);
    if (ths->size >= ths->capacity) {
        memory_controller_error_e status = memory_controller_multiply_2(controller);
        if (status == ERROR) return ERROR;
    }
    ths->array[ths->size] = value;
    ths->size++;
}

memory_controller_error_e memory_controller_push_array(memory_controller_t controller, uint8_t* array, int size)
{
    memory_controller_data_t* ths = CONVERT_POINTER(controller);
    int __new_size = ths->size + size;
    if (__new_size >= ths->capacity) {
        memory_controller_error_e status = memory_controller_multiply_2(controller);
        if (status == ERROR) return ERROR;
    }
    // memcpy(ths->array + ths->size, array, size);
    ths->size = __new_size;
}