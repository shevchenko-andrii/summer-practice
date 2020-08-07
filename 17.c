#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int num;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node *head;
    Node *end;
} DoubleList;


DoubleList *createList() {
    DoubleList *tmp = malloc(sizeof *tmp);
    tmp->size = 0;
    tmp->head = tmp->end = NULL;
    return tmp;
}

void addNum(DoubleList *plist, int num) {
    Node *tmp = malloc(sizeof *tmp);
    tmp->num = num;
    tmp->next = NULL;
    tmp->prev = plist->end;

    if (plist->end) {
        plist->end->next = tmp;
    }
    plist->end = tmp;

    if (plist->head == NULL) {
        plist->head = tmp;
    }

    plist->size++;
}

void printList(DoubleList *plist) {
    for (Node *pnode = plist->head; pnode; pnode = pnode->next)
        printf_s("%d\t", pnode->num);
    printf_s("\n");
}

int main(int argc, char *argv[]) {
    DoubleList *list = createList();
    int sum = 0, i = 1, n;

    printf_s("n = ");
    scanf_s("%d", &n);

    srand(time(NULL));

    while (n--) {
        int num = rand() % 16 - 10;
        if ((i++) % 3 == 0) sum += num;
        addNum(list, num);
    }

    printList(list);

    Node *tmp = list->head;
    list->head = list->head->next;
    free(tmp);

    list->end = list->end->prev;
    list->end->next = NULL;

    printList(list);

    printf_s("sum = %d\n", sum);

    return 0;
}