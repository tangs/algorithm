#include <stdio.h>
#include <stdlib.h>

// #include "List.h"
#include "DuLinkList.h"

void PrintElements(List l) {
    Position p = First(l);
    while (p && p != l) {
        printf("%d\n", Retrieve(p));
        p = Advance(p);
    }
}

int main() {
    List l = CreateList();
    Append(0, l);
    Append(1, l);
    Append(2, l);
    Append(3, l);
    Append(4, l);
    Append(5, l);
    Append(6, l);
    Append(7, l);
    Append(8, l);

    // 3.3
    Swap(0, 1, l);

    PrintElements(l);
    
    DeleteList(l);
    free(l);
    return 0;
}
