#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void swap(int *pa, int *pb);

int main(int argc, char *argv[]) {
    int A[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 20 + 1;
        printf("%d\t", A[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        int flag = 0, min = i;
        for (int j = i; j < N - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
            if (A[j] < A[min]) min = j;
        }
        if (flag == 0) break;
        if (min != i) {
            swap(&A[i], &A[min]);
        }
    }

    for (int i = 0; i < N; i++) printf("%d\t", A[i]);

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 4; i++) {
        sum1 += A[i];
    }

    for (int i = 4; i < N; i++) {
        sum2 += A[i];
    }

    printf("\ndiv = %.2f\n", (float) sum2 / (float) sum1);

    return 0;
}

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}