#include <stdio.h>

#include "ArrList.h"

void ShowList(List l) {
    Position p = First(l);
    while (p != POS_END) {
        printf("%d ", Retrieve(p, l));
        p = Advance(p, l);
    }
    printf("\n");
}

int main() {
    List l = CreateList(100);
    for (int i = 9; i >= 0; --i) {
        Insert(i, 0, l);
    }
    ShowList(l);
    printf("%d\n", Delete(3, l));
    printf("%d\n", Delete(5, l));
    printf("%d\n", Delete(7, l));
    printf("%d\n", Delete(8, l));
    printf("%d\n", Delete(2, l));
    // delete element: 4
    printf("%d\n", Delete(2, l));
    ShowList(l);
    return 0;
}
