#include <stdio.h>

int main() {
    double x, y;

    printf_s("x = ");
    scanf_s("%lf", &x);

    printf_s("y = ");
    scanf_s("%lf", &y);

    if (x > 0) {
        if (x * x + y * y <= 25) {
            if (y > 0) {
                if (x * x + y * y > 9) {
                    printf_s("YES\n");
                }
            } else {
                printf_s("YES\n");
            }
        } else {
            printf_s("NO\n");
        }
    } else {
        printf_s("NO\n");
    }

    return 0;
}
