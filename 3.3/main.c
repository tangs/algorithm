#include <stdio.h>

#include "Stack.h"

int main() {
    Stack s = CreateStack();
    Push(34, s);
    Push(66, s);
    Push(4, s);
    Push(7, s);
    Push(26, s);
    while(!IsEmpty(s)) {
        printf("%d\n", Top(s));
        Pop(s);
    }
    return 0;
}
