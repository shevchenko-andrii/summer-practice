#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int day, mount, year;
} day_t;

typedef struct {
    char surname[15];
    char name[15];
    char parentName[15];
    char sex;
    day_t birthday;
} Student;

void getDay(day_t *_time) {
    scanf_s("%d%d%d", &_time->day, &_time->mount, &_time->year);
}

Student *getStudent() {
    Student *stud = malloc(sizeof *stud);
    printf_s("Enter info student or press 'Enter' to end...\n");

    printf_s("Surname: ");
    fflush(stdin);
    fgets(stud->surname, 15, stdin);
    if (strcmp(stud->surname, "\n") == 0) return NULL;
    stud->surname[strlen(stud->surname) - 1] = 0;

    printf_s("Name: ");
    fflush(stdin);
    fgets(stud->name, 15, stdin);
    stud->name[strlen(stud->name) - 1] = 0;

    printf_s("Parent name: ");
    fflush(stdin);
    fgets(stud->parentName, 15, stdin);
    stud->parentName[strlen(stud->parentName) - 1] = 0;

    printf_s("Sex: ");
    fflush(stdin);
    scanf_s("%c", &stud->sex);

    printf_s("Birthday: ");
    getDay(&stud->birthday);

    return stud;
}

Student studDup(Student *src) {
    Student dup;
    strcpy_s(dup.surname, sizeof src->surname, src->surname);
    strcpy_s(dup.name, sizeof src->name, src->name);
    strcpy_s(dup.parentName, sizeof src->parentName, src->parentName);
    dup.sex = src->sex;
    dup.birthday = src->birthday;
    return dup;
}

int isMale(int c) { return 'm' == tolower(c); }
int iSFallWinterBirthday(day_t birthday) {
    if (birthday.year == 1998) {
        if (birthday.mount > 9 && birthday.mount < 12)
            return 1;
    }
    return 0;
}

void printStudent(Student *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf_s("Surname: %s\t", arr[i].surname);
        printf_s("Name: %s\t", arr[i].name);
        printf_s("Parent name: %s\t", arr[i].parentName);
        printf_s("Sex: %c\t", arr[i].sex);
        printf_s("Birthday: %d.%d.%d\n", arr[i].birthday.day,
                 arr[i].birthday.mount, arr[i].birthday.year);
    }
}

int main(int argc, char *argv[]) {
    Student *studs, *result;
    int n = 1, i = 0, j = 0, m = 1;

    studs = malloc(sizeof *studs);
    if (studs == NULL) return 1;
    result = malloc(sizeof *result);
    if (result == NULL) return 1;

    while (1) {
        Student *tmp = getStudent();
        if (tmp == NULL) break;
        studs[i++] = studDup(tmp);
        if (isMale(studs[i].sex) && iSFallWinterBirthday(studs[i].birthday)) {
            if (j != 0) {
                result = realloc(result, ++m * sizeof *result);
                if (result == NULL) return 1;
            }
            result[j++] = studs[i];
        }
        studs = realloc(studs, ++n * sizeof *studs);
        if (studs == NULL) return 1;
        system("cls");
    }

    printStudent(studs, n);
    system("cls");
    system("pause");
    printStudent(result, m);

    return 0;
}