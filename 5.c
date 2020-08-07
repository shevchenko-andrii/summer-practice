#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 4

int main(int argc, char *argv[]) {
    int L[N][M];

    srand(time(NULL));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            L[i][j] = rand() % 101;
            printf_s("%d\t", L[i][j]);
        }
        printf_s("\n");
    }

    printf_s("\n");
    for (int j = 0; j < M; ++j) {
        int avg = 0;
        for (int i = 0; i < N; ++i) {
            avg += L[i][j];
        }
        printf("%.2f\t", (float) avg / (float) N);
    }

    return 0;
}