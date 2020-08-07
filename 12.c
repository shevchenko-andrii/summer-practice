#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int **matrix, n;
    printf_s("n");
    scanf_s("%d", &n);

    matrix = malloc(n * sizeof *matrix);
    if (matrix == NULL) return 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i] = malloc(n * sizeof **matrix);
            if (matrix[i] == NULL) return 1;
        }
    }

    int sum = 0, count = 0;
    for (int i = 0; i < n; ++i, printf_s("\n")) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 21 + 1;
            printf_s("%d\t", matrix[i][j]);

            count += matrix[i][j] < 3;
            if ((i == j) || (j == n - 1 - i)) sum += matrix[i][j];
        }
    }

    printf_s("\ncount = %d\tsum = %d\n", count, sum);


    return 0;
}