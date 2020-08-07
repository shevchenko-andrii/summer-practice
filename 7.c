#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n, m, **A, index = -1;

    printf_s("n = ");
    scanf_s("%d", &n);
    printf_s("m = ");
    scanf_s("%d", &m);

    srand(time(NULL));

    A = malloc(n * sizeof *A);
    if (A == NULL) return 1;

    for (int i = 0; i < n; ++i) {
        int flag = 1;
        for (int j = 0; j < m; ++j) {
            A[i] = malloc(m * sizeof **A);
            if (A[i] == NULL) return 1;
            A[i][j] = rand() % 200 + 1;
            printf_s("%d\t", A[i][j]);
            if (A[i][j] % 2 != 0) flag = 0;
        }
        printf_s("\n");
        if (flag == 1) index = i;
    }

    if (index != -1) printf("number = %d", index);
    else printf_s("Nothing.\n");

    return 0;
}