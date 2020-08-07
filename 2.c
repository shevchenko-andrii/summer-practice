#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 13

int main(int argc, char *argv[]) {
    int H[N], min = INT_MAX, index = -1;

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        H[i] = rand() % 21 + 1;
        if (H[i] % 2 != 0) {
            if (min > H[i]) {
                min = H[i];
                index = i;
            }
        }
        printf("%d\t", H[i]);
    }

    printf("\nmin = %d\tindex = %d\n", min, index);

    return 0;
}