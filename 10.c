#include <stdio.h>
#include <string.h>
#include <ctype.h>

void isSymbolInString(int countSymbol, char symbol) {
    countSymbol
        ? printf_s("%c = %d\n", symbol, countSymbol)
        : printf_s("No '%c' in string\n", symbol);
}

int main(int argc, char *argv[]) {
    char string[256];

    printf_s("String: ");
    fgets(string, 256, stdin);

    int countOfA = 0, countOfB = 0;
    for (int i = 0; string[i]; ++i) {
        countOfA += isupper(string[i]) == 'A';
        countOfB += isupper(string[i]) == 'B';
    }

    printf_s("len = %d\n", strlen(string));
    isSymbolInString(countOfA, 'a');
    isSymbolInString(countOfB, 'b');

    return 0;
}