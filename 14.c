#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define isVowel(c) ( strchr("AEIOUY", toupper(c)) )

void deleteVowels(char *str) {
    for (char *p = str; *p = *str++; !isVowel(*p) ? p++ : 0);
}

void deletePuncts(char *str) {
    for (char *p = str; *p = *str++; !ispunct(*p) ? p++ : 0);
}

void foo(char *str) { deletePuncts(str), deleteVowels(str); }

int main(int argc, char *argv[]) {
    char *s, buf[256];

    printf_s("S = ");
    fgets(buf, sizeof buf, stdin);

    s = malloc(sizeof buf + 1);
    if (s == NULL) return 1;
    strcpy_s(s, sizeof buf, buf);

    foo(s);
    printf_s("%s", s);

    return 0;
}