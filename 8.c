#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *pa, int *pb);

int main(int argc, char *argv[]) {
    int n, **A;

    printf_s("n = ");
    scanf_s("%d", &n);

    srand(time(NULL));

    A = malloc(n * sizeof *A);
    if (A == NULL) return 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i] = malloc(n * sizeof **A);
            if (A[i] == NULL) return 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = rand() % 101;
            printf_s("%d\t", A[i][j]);
        }
        printf_s("\n");
    }

    printf_s("\nSorted:\n");
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int num = 0; num < n * n - 1; ++num) {
            int i1 = num / n, i2 = (num + 1) / n;
            int j1 = num % n, j2 = (num + 1) % n;
            if (A[i1][j1] < A[i2][j2]) {
                swap(&A[i1][j1], &A[i2][j2]);
                flag = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf_s("%d\t", A[i][j]);
        }
        printf_s("\n");
    }

    return 0;
}

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}