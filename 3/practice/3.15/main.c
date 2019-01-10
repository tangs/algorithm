#include <stdio.h>

#include "ArrList.h"

void ShowList(List l) {
    Position p = First(l);
    while (p) {
        printf("%d ", Retrieve(p));
        p = Advance(p, l);
    }
    printf("\n");
}

int main() {
    InitializeCursorSpace();
    List l = CreateList();
    for (int i = 0; i < 10; ++i)
        Add(i, l);    
    ShowList(l);
    Find(4, l);
    Find(6, l);
    Find(2, l);
    ShowList(l);
    MakeEmpty(l);
    return 0;
}
