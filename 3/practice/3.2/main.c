#include <stdio.h>
#include <stdlib.h>

#include "List.h"

Position GetPositionByIndex(List l, ElementType index) {
    Position p = First(l);
    for (int i = 0; i < index; ++i) {
        p = Advance(p);
        if (p == NULL) {
            // printf("Err index(%d) in List:%p\n", index, l);
            return NULL;
        }
    }
    return p;
}

// 3.2
void PrintLots(List l, List p) {
    Position keyP = First(p);
    while(keyP) {
        ElementType key = Retrieve(keyP);
        Position valueP = GetPositionByIndex(l, key);
        if (valueP) {
            printf("key:%d value:%d\n", key, Retrieve(valueP));
        } else {
            printf("err index(%d) in List(%p)\n", key, l);
        }
        keyP = Advance(keyP);
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
    List p = CreateList();
    Append(2, p);
    Append(3, p);
    Append(4, p);
    Append(8, p);
    PrintLots(l, p);

    DeleteList(l);
    free(l);
    DeleteList(p);
    free(p);
    return 0;
}
