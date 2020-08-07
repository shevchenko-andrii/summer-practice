#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char    *lines[256];
    int n = 0;

    while (1) {
        char tmp[256];
        printf_s("Press `enter` to end or enter string: ");
        fgets(tmp, sizeof tmp, stdin);
        if (strcmp(tmp, "\n") == 0) break;
        lines[n] = malloc(strlen(tmp) + 1);
        if (lines[n] == NULL) return 1;
        strcpy_s(lines[n++], strlen(tmp) + 1, tmp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(lines[i]); j++) {
            if (isdigit(lines[i][j])) lines[i][j] = '*';
        }
        printf_s("%s", lines[i]);
    }


    return 0;
}