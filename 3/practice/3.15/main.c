#include <stdio.h>

// #include "ArrList.h"
#include "LinkedList.h"

void ShowList(List l) {
    Position p = First(l);
    Position h = Header(l);
    while (p && p != h) {
        // printf("%d ", Retrieve(p));
        printf("%d, find count:%d\n", Retrieve(p), GetFindCount(p));
        p = Advance(p, l);
    }
    printf("\n");
}

int main() {
    // InitializeCursorSpace();
    List l = CreateList();
    for (int i = 0; i < 10; ++i)
        Add(i, l);    
    ShowList(l);
    Find(4, l);
    Find(6, l);
    Find(0, l);
    Find(6, l);
    Find(2, l);
    Find(6, l);
    Find(3, l);
    Find(6, l);
    Find(5, l);
    ShowList(l);
    MakeEmpty(l);
    return 0;
}
