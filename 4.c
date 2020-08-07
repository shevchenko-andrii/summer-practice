#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 7

void swap(int *pa, int *pb);

int main(int argc, char *argv[]) {
    int U[N][M];

    srand(time(NULL));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            U[i][j] = rand() % 201 - 100;
            printf_s("%d\t", U[i][j]);
        }
        printf_s("\n");
    }
    printf_s("\n");

    int *pmin = &U[0][0], *pmax = &U[0][0];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (*pmin > U[i][j]) pmin = &U[i][j];
            if (*pmax < U[i][j]) pmax = &U[i][j];
        }
    }

    swap(pmin, pmax);
    for (int i = 0; i < N; ++i, printf_s("\n"))
        for (int j = 0; j < M; ++j)
            printf_s("%d\t", U[i][j]);
    printf_s("\n");

    return 0;
}

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}