#include <stdio.h>
#include <stdlib.h>

struct List {
    int value;
    struct List* next;
};

void removeNext(struct List* start) {
    printf("removing %d..\n", start->next->value);
    struct List* newNext = start->next->next;
    free(start->next);
    start->next = newNext;
}

void print(struct List* start, int n) {
    printf("generated list: [%d", start->value);
    start = start->next;

    for (int i = 1; i < n; i++) {
        printf(", %d", start->value);
        start = start->next;
    }
    printf("]\n");
}

struct List* josephus(struct List* start, int s) {
    for (int i = 0; i < s - 1; i++) {
        start = start->next;
    }
    removeNext(start);
    return start;
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    if (n < 1) {
        printf("length has to be at least 1. terminating..\n");
        return -1;
    } else if (argc != 3) {
        printf("invalid number of arguments. terminating..\n");
    }
    int s = atoi(argv[2]);
    printf("N: %d\ns: %d\n", n, s);

    struct List* start = malloc(sizeof(struct List));
    start->value = 0;

    struct List* last = start;

    for (int i = 1; i < n; i++) {
        struct List* next = malloc(sizeof(struct List));
        next->value = i;
        last->next = next;
        last = next;
    }
    last->next = start;
    print(start, n);

    start = josephus(last, s);

    while (start->next != start) {
        start = josephus(start, s);
    }
    printf("result: %d\n", start->value);
    free(start);
    return 0;
}