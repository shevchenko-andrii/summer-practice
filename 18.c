#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file, *fileTmp;
    char fileName[FILENAME_MAX], buffer[BUFSIZ];


    printf_s("File name:");
    fflush(stdin);
    fgets(fileName, FILENAME_MAX, stdin);
    fileName[strlen(fileName) - 1] = 0;

    fopen_s(&file, fileName, "rt");
    if (file == NULL) return 1;
    fopen_s(&fileTmp, "delete.txt", "wt");
    if (fileTmp == NULL) return 1;

    int k;
    printf_s("k = ");
    scanf_s("%d", &k);

    while ((fgets(buffer, BUFSIZ, file)) != NULL) {
        if (strlen(buffer) < k) {
            strcpy_s(buffer, strlen(buffer + k), buffer + k);
            fputs(buffer, fileTmp);
        }
    }

    fclose(file);
    fclose(fileTmp);

    remove(fileName);
    rename("delete.txt", fileName);

    return 0;
}