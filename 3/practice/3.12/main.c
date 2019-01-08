#include <stdio.h>

#include "LinkedList.h"

void ShowList(List l) {
    Position p = First(l);
    while (p) {
        printf("%d\n", Retrieve(p, l));
        p = Advance(p, l);
    }
    printf("\n");
}

int main() {
    List l = CreateList();
    for (int i = 0; i < 100; ++i)
        Insert(i, l, l);
    ShowList(l);
    Reverse(l);
    ShowList(l);
    return 0;
}