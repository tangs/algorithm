#include "Stack.h"

#include <stdio.h>

int main() {
    Stack s = Stack_Create();
    srand(time());
    for (int i = 0; i < 20; ++i) {
        int num = rand() % 1000;
        printf("%d ", num);
        Stack_Push(num, s);
    }
    printf("\n");
    while (!Stack_IsEmpty(s)) {
        printf("min:%d\n", Stack_FindMin(s));
        Stack_Pop(s);
    }
    Stack_DisposeStack(s);
    return 0;
}
