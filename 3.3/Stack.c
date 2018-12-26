#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    PtrToNode next;
};

int IsEmpty(Stack s) {
    return s->next == NULL;
}

Stack CreateStack(void) {
    Stack s = malloc(sizeof(struct Node));
    s->next = NULL;
    return s;
}

void DisposeStack(Stack s) {
    MakeEmpty(s);
    free(s);
}

void MakeEmpty(Stack s) {
    while(s->next)
        Pop(s);
}

void Push(ElementType x, Stack s) {
    PtrToNode p = malloc(sizeof(struct Node));
    p->next = NULL;
    p->element = x;
    PtrToNode last = s;
    while(last->next)
        last = last->next;
    last->next = p;
}

ElementType Top(Stack s) {
    PtrToNode last = s;
    while(last->next)
        last = last->next;
    if (last == s)
        // todo
        printf("It's null stack.");
    return last->element;
}

void Pop(Stack s) {
    PtrToNode last = s;
    PtrToNode prev = s;
    while(last->next) {
        prev = last;
        last = last->next;
    }
    if (last == s)
        // todo
        printf("It's null stack.");
    free(last);
    prev->next = NULL;
}
