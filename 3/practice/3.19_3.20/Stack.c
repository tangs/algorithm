#include "Stack.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};

Stack CreateStack(void) {
    Stack s = malloc(sizeof(struct Node));
    if (!s) {
        // out of memory.
        return NULL;
    }
    s->element = 0;
    s->next = NULL;
    return s;
}

void MakeEmpty(Stack s) {
    Position p = s->next, tmp;
    while (p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

void DisposeStack(Stack s) {
    MakeEmpty(s);
    free(s);
}

int IsEmpty(Stack s) {
    return s->next == NULL;
}

void Push(ElementType x, Stack s) {
    Position p = malloc(sizeof(struct Node));
    if (!p) {
        // out of memory.
        return;
    }
    p->element = x;
    p->next = s->next;
    s->next = p;
}

void Pop(Stack s) {
    Position p = s->next;
    if (!p)
        // stack is empty.
        return;
    s->next = p->next;
    free(p);
}

ElementType Top(Stack s) {
    Position p = s->next;
    if (!p)
        // stack is empty.
        return 0;
    return p->element;
}

ElementType TopAndPop(Stack s) {
    Position p = s->next;
    if (!p)
        // stack is empty.
        return 0;
    ElementType x = p->element;
    s->next = p->next;
    free(p);
    return x;
}
