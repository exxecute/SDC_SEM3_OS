#include <stdio.h>
#include <stdlib.h>

#include "src/calculator/calculator.h"
#include "src/io_array/io_array.h"
#include "src/sorter/sorter.h"

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
   
    sorter_bubble_sort(array, n);
    printf("Sorted array: ");
    print_array(array, n);

    free(array);

    return 0;
}
