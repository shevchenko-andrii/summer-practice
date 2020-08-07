#include <stdio.h>
#include <string.h>
#include <ctype.h>

static inline int isVowel(int c) {
    static char *vowels = "AEUIOY";
    return strchr(vowels, toupper(c)) != NULL;
}

static char *compress(char *str) {
    char *p = str;
    while (*p) {
        while (*p && isspace(*p)) p++;
        if (!*p) break;
        if (!isVowel(*p)) {
            char *end = p;
            while (*end && !isspace(*end)) end++;
            while (*end && isspace(*end)) end++;
            memmove(p, end, strlen(end) + 1);
        } else {
            while (*p && !isspace(*p)) p++;
        }
    }

    return str;
}

int main(int argc, char *argv[]) {
    char s[256];

    printf_s("S = ");
    fgets(s, sizeof s, stdin);
    s[strlen(s) - 1] = 0;

    printf_s("After: %s\n", compress(s));

}
