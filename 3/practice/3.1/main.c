#include <stdio.h>

#include "List.h"

// 3.1
void printElements(List l) {
    Position p = First(l);
    while (p) {
        printf("%d\n", Retrieve(p));
        p = Advance(p);
    }
}

int main() {
    List l = CreateList();
    Append(1, l);
    Append(2, l);
    Append(3, l);
    Append(4, l);
    Append(5, l);
    Append(6, l);
    Append(7, l);
    Append(8, l);
    printElements(l);
    return 0;
}
