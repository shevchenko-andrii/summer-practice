#include <stdio.h>
#include <stdlib.h>

int Sn(int n, int d, int a1) {
    return n == 1 ? a1 : a1 + Sn(n - 1, d, a1 + d);
}

int main(int argc, char *argv[]) {
    int n, d, a1;

    printf_s("n, d, a1  = ");
    scanf_s("%d%d%d", &n, &d, &a1);

    printf_s("Sn = %d\n", Sn(n, d, a1));

    return 0;
}