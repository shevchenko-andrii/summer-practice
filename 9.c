#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 6
#define N 5

int main(int argc, char *argv[]) {
    int a[K][N], n, count = 0;

    srand(time(NULL));
    printf_s("n = ");
    scanf_s("%d", &n);

    for (int i = 0; i < K; ++i, printf_s("\n")) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = rand() % 290;
            if (a[i][j] > n) count++;
            printf_s("%d\t", a[i][j]);
        }
    }

    printf_s("\ncount = %d\n", count);

    return 0;
}