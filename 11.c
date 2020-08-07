#include <stdio.h>
#include <stdlib.h>

void swap(int *pa, int *pb) { int tmp = *pa; *pa = *pb; *pb = tmp; }

int main(int argc, char *argv[]) {
    int *array, lenArray, count = 0, product = 1;
    printf_s("n = ");
    scanf_s("%d", &lenArray);
    array = malloc(lenArray * sizeof *array);

    for (int i = 0; i < lenArray; ++i) {
        array[i] = rand() % 101;
        product *= array[i];
        count += (array[i] > 40) && (array[i] < 60);
        printf_s("%d\t", array[i]);
    }
    printf_s("\n");
    printf_s("product = %d\tcount = %d\n", product, count);

    for (int i = 0; i < lenArray; i++) {
        int flag = 0, min = i;
        for (int j = i; j < lenArray - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                flag = 1;
            }
            if (array[j] < array[min]) min = j;
        }
        if (flag == 0) break;
        if (min != i) {
            swap(&array[i], &array[min]);
        }
    }

    for (int i = 0; i < lenArray; ++i) {
        printf_s("%d\t", array[i]);
    }

    return 0;
}
