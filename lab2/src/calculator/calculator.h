#ifndef CALCULATOR_H_
#define CALCULATOR_H_

typedef struct calculator_data 
{
    int sum;
    float average;
    int min;
    int max;
    int even_count;
    int odd_count;
}calculator_data_t;

void calculator_count_all(int* array, int size, calculator_data_t* data);
void calculator_print(calculator_data_t data);

#endif // CALCULATOR_H_