#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[45];
    int height;
} Mountain;

int main(int argc, char *argv[]) {
    FILE *file;
    char fileName[FILENAME_MAX];
    Mountain mountains[15];

    printf_s("File name: ");
    fgets(fileName, FILENAME_MAX, stdin);
    fileName[sizeof fileName - 1] = 0;

    fopen_s(&file, fileName, "rt");
    for (int i = 0; !feof(file); i++) {
        fscanf_s(file,"%s %d", mountains[i].name, &mountains[i].height);
    }

    for (int i = 0; i < 15; ++i) {
        if (mountains[i].height > 3000) {
            printf_s("%s\n", mountains[i].name);
        }
    }

    return 0;
}
