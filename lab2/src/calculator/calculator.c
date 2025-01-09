#include "calculator.h"
#include <limits.h>

static int __calculator_sum(int* array, int size);
static float __calculator_average(int sum, int size);
static void __calculator_min_max(int* array, int size, int* min, int* max);
static void __calculator_even_odd(int* array, int size, int* even_count, int* odd_count) ;

void calculator_count_all(int* array, int size, calculator_data_t* data)
{
    data->sum = __calculator_sum(array, size);
    data->average = __calculator_average(data->sum, size);
    __calculator_min_max(array, size, &data->min, &data->max);
    __calculator_even_odd(array, size, &data->even_count, &data->odd_count);
}

void calculator_print(calculator_data_t data)
{
    printf("Sum: %d\n", data.sum);
    printf("Average: %.2f\n", data.average);
    printf("Minimum: %d\n", data.min);
    printf("Maximum: %d\n", data.max);
    printf("Even numbers: %d\n", data.even_count);
    printf("Odd numbers: %d\n", data.odd_count);
}


static int __calculator_sum(int* array, int size) 
{
    int __sum = 0;
    for (int i = 0; i < size; i++) 
    {
        __sum += array[i];
    }
    return __sum;
}

static float __calculator_average(int sum, int size) 
{
    return (float) (sum / size);
}

static void __calculator_min_max(int* array, int size, int* min, int* max) 
{
    *min = INT_MAX;
    *max = INT_MIN;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] < *min) *min = array[i];
        if (array[i] > *max) *max = array[i];
    }
}

static void __calculator_even_odd(int* array, int size, int* even_count, int* odd_count) 
{
    *even_count = 0;
    *odd_count = 0;
    for (int i = 0; i < size; i++) 
    {
        if (array[i] % 2 == 0)  (*even_count)++;
        else                    (*odd_count)++;
    }
}