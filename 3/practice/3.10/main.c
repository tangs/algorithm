#include <stdio.h>

#include "CricLinkedList.h"

void josephus(int m, int n) {
    List l = CreateList();
    for (int i = 0; i < n; ++i)
        Append(i + 1, l);
    Position p = First(l);
    int idx = 0;
    while (!IsEmpty(l)) {
        if (idx++ == m) {
            printf("del:%d\n", Retrieve(p, l));
            Delete(p, l);
            idx = 0;
        }
        p = Advance(p, l);
    }
    printf("\n");
    DisposeList(l);
}

int main() {
    josephus(0, 5);
    josephus(1, 5);
    return 0;
}
