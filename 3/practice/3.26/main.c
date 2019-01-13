#include "Deque.h"

#include <stdio.h>

void ShowAndPop(Deque d) {
    while (!Deque_IsEmpty(d)) {
        printf("%d ", Deque_Pop(d));
    }
    printf("\n");
}

void ShowAndEject(Deque d) {
    while (!Deque_IsEmpty(d)) {
        printf("%d ", Deque_Eject(d));
    }
    printf("\n");
}

int main() {
    Deque d = Deque_Create();
    for (int i = 0; i < 10; ++i)
        Deque_Push(i, d);
    for (int i = 90; i < 100; ++i)
        Deque_Inject(i, d);
    ShowAndPop(d);
    for (int i = 0; i < 10; ++i)
        Deque_Push(i, d);
    for (int i = 90; i < 100; ++i)
        Deque_Inject(i, d);
    ShowAndEject(d);
    Deque_Dispose(d);
    return 0;
}
