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
    // s->element = 0;
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
    s->next = NULL;
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
    Position top = s->next;
    if (!top) {
        // Stack is empty.
        return;
    }
    s->next = top->next;
    free(top);
}

ElementType Top(Stack s) {
    Position top = s->next;
    if (!top) {
        // Stack is empty.
        ElementType data;
        return data;
    }
    return top->element;
}

ElementType TopAndPop(Stack s) {
    Position top = s->next;
    if (!top) {
        // Stack is empty.
        ElementType data;
        return data;
    }
    ElementType element = top->element;
    s->next = top->next;
    free(top);
    return element;
}
