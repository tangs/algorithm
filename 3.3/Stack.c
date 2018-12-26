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
    if (s == NULL) 
        printf("Out of space.");
    s->next = NULL;
    return s;
}

void DisposeStack(Stack s) {
    MakeEmpty(s);
    free(s);
}

void MakeEmpty(Stack s) {
    while(!IsEmpty(s))
        Pop(s);
}

void Push(ElementType x, Stack s) {
    PtrToNode p = malloc(sizeof(struct Node));
    if (s == NULL) {
        printf("Out of space.");
    } else {
        p->next = s->next;
        p->element = x;
        s->next = p;
    }
}

ElementType Top(Stack s) {
    if (IsEmpty(s)) {
        printf("It's null stack.");
        return 0;
    } else {
        return s->next->element;
    }
}

void Pop(Stack s) {
    if (IsEmpty(s)) {
        printf("It's null stack.");
    } else {
        PtrToNode p = s->next;
        s->next = p->next;
        free(p);
    }
}
