#include <stdio.h>
#include <stdlib.h>

#include "src/calculator/calculator.h"
#include "src/io_array/io_array.h"

int calculateSum(int* array, int size);
float calculateAverage(int sum, int size);
void findMinMax(int* array, int size, int* min, int* max);
void countEvenOdd(int* array, int size, int* evenCount, int* oddCount);
void bubbleSort(int* array, int size);

int main() {
    int n;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements. Exiting program.\n");
        return 1;
    }

   
    int* array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    
    input_array(array, n);

    calculator_data_t calculator_data;
    calculator_count_all(array, n, &calculator_data);
    calculator_print(calculator_data);
   
    bubbleSort(array, n);
    printf("Sorted array: ");
    print_array(array, n);

    free(array);

    return 0;
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
