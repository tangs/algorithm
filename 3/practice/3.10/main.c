#include <stdio.h>

#include "CricLinkedList.h"

void josephus(int m, int n) {
    List l = CreateList();
    // for (int i = 0; i < n; ++i)
    //     Append(i + 1, l);
    for (int i = n; i > 0; --i)
        Insert(i, l, l);
    Position p = First(l);
    int idx = 0;
    while (!IsEmpty(l)) {
        if (idx++ == m) {
            int value = Retrieve(p, l);
            printf("del:%d\n", value);
            p = Delete(p, l);
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
    josephus(400, 500000);
    return 0;
}
