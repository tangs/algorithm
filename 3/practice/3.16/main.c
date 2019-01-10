#include <stdio.h>

#include "ArrList.h"

void ShowList(List l) {
    Position p = First(l);
    while (p) {
        printf("%d ", Retrieve(p, l));
        p = Advance(p, l);
    }
    printf("\n");
}

int main() {
    List l = CreateList(100);
    Position header = Header(l);
    for (int i = 0; i < 100; ++i) {
        Insert(rand() % 50, header, l);
    }
    ShowList(l);
    // O(N^3)
    DeleteRepeat(l);
    ShowList(l);
    return 0;
}