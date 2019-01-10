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
    List l = CreateList(200);
    Position header = Header(l);
    for (int i = 0; i < 200; ++i) {
        Insert(rand() % 1000, header, l);
    }
    ShowList(l);
    // O(N^3)
    // DeleteRepeat(l);
    QuickSort(l);
    ShowList(l);
    return 0;
}