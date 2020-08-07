#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmp(char *str) {
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] < str[i - 1]) return 0;
    }

    return 1;
}

char *readf(char *fileName) {
    FILE    *fptr;
    char    *buf;

    fopen_s(&fptr, fileName, "rt");
    if (fptr == NULL) return NULL;

    fseek(fptr, 0, SEEK_END);
    size_t  size = ftell(fptr);
    buf = malloc(size + 1);

    fseek(fptr, 0, SEEK_SET);
    size = fread(buf, 1, size, fptr);
    buf[size] = 0;

    fclose(fptr);

    return buf;
}


int main(int argc, char *argv[]) {
    char    fileName[FILENAME_MAX];
    char    *words[100], *del = " ,.;:!\n\t\r?";

    printf_s("File name: ");
    fgets(fileName, FILENAME_MAX, stdin);
    fileName[strlen(fileName) - 1] = 0;

    char    *buf = readf(fileName);
    char    *token = NULL;
    char    *word = strtok_s(buf, del, &token);

    size_t  count = 0;

    while (word != NULL) {
        size_t  len = strlen(word);
        if (cmp(word)) {
            words[count] = malloc(len + 1);
            strcpy_s(words[count++], len + 1, word);
        }

        word = strtok_s(NULL, del, &token);
    }

    free(buf);
    for (int i = 0; i < count; ++i) {
        printf_s("%s\n", words[i]);
    }    

    return 0;
}