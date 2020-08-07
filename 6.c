#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main(int argc, char *argv[]) {
    int D[N][N];

    srand(time(NULL));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            D[i][j] = rand() % 3;
            printf_s("%d\t", D[i][j]);
        }
        printf_s("\n");
    }
    printf_s("\n");

    int min = D[0][0];
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            if (min > D[i][j]) min = D[i][j];
            sum += D[i][j];
        }
        if (D[i][i] == 0) printf_s("%d\t", sum);
    }

    printf_s("\nmin = %d\n", min);

    return 0;
}