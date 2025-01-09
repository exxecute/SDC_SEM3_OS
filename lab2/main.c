#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void inputArray(int* array, int size);
int calculateSum(int* array, int size);
float calculateAverage(int sum, int size);
void findMinMax(int* array, int size, int* min, int* max);
void countEvenOdd(int* array, int size, int* evenCount, int* oddCount);
void bubbleSort(int* array, int size);
void printArray(int* array, int size);

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

    
    inputArray(array, n);

   
    int sum = calculateSum(array, n);
    float average = calculateAverage(sum, n);
    int min, max;
    findMinMax(array, n, &min, &max);
    int evenCount, oddCount;
    countEvenOdd(array, n, &evenCount, &oddCount);

    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Even numbers: %d\n", evenCount);
    printf("Odd numbers: %d\n", oddCount);

   
    bubbleSort(array, n);
    printf("Sorted array: ");
    printArray(array, n);

    
    free(array);

    return 0;
}

void inputArray(int* array, int size) {
    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

int calculateSum(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

float calculateAverage(int sum, int size) {
    return (float)sum / size;
}

void findMinMax(int* array, int size, int* min, int* max) {
    *min = INT_MAX;
    *max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (array[i] < *min) {
            *min = array[i];
        }
        if (array[i] > *max) {
            *max = array[i];
        }
    }
}

void countEvenOdd(int* array, int size, int* evenCount, int* oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
    }
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

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}