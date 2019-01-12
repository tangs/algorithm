#include "Stack.h"

#include <stdio.h>

void ShowAndPopStack(Stack s, int isHead) {
    while (!Stack_IsEmpty(s, isHead)) {
        printf("%d ", Stack_TopAndPop(s, isHead));
    }
    printf("\n");
}

int main() {
    Stack s = Stack_Create(10);
    for (int i = 0; i < 100; ++i) {
        int isHead = i % 2;
        int ret = Stack_Push(i, s, isHead);
        printf("add %d to %d, ret:%d\n", i, isHead, ret);
        if (!ret)
            break;
    }
    ShowAndPopStack(s, 0);
    ShowAndPopStack(s, 1);
}
