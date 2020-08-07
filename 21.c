#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int symmetry(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] != str[len - 1 - i]) return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    char        str[256], *words[100];
    char        *token = NULL, *word;
    const char  *del = " .,:;\n\t\r!?";
    size_t  count = 0;

    printf_s("String: ");
    fgets(str, sizeof str, stdin);
    str[strlen(str) - 1] = 0;

    word = strtok_s(str, del, &token);
    while (word != NULL) {
        if (symmetry(word)) {
            size_t  len = strlen(word);
            words[count] = malloc(len + 1);
            strcpy_s(words[count++], len + 1, word);
        }
        word = strtok_s(NULL, del, &token);
    }

    for (int i = 0; i < count; ++i) {
        printf_s("%s\n", words[i]);
    }

    for (int i = 0; i < count; free(words[i++]));
}