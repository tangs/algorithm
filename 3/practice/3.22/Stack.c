#include "Stack.h"

#include <stdlib.h>

#include <stack.h>

struct Stack_Node {
    ElementType element;
    PtrToNode next;
    ElementType min;
};

Stack Stack_Create(void) {
    Stack s = malloc(sizeof(struct Stack_Node));
    if (!s) {
        // out of memory.
        return NULL;
    }
    s->next = NULL;
    s->element = 0;
    s->min = ELEMENT_MAX;
    return s;
}

void Stack_MakeEmpty(Stack s) {
    StackPos p = s->next, tmp;
    while (p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

void Stack_DisposeStack(Stack s) {
    Stack_MakeEmpty(s);
    free(s);
}

int Stack_IsEmpty(Stack s) {
    return s->next == NULL;
}

int Stack_Push(ElementType x, Stack s) {
    StackPos p = malloc(sizeof(struct Stack_Node));
    if (!p) {
        // out of memory.
        return 1;
    }
    p->element = x;
    p->min = x;
    if (s->next && s->next->min < x)
        p->min = s->next->min;
    p->next = s->next;
    s->next = p;
    return 0;
}

void Stack_Pop(Stack s) {
    if (Stack_IsEmpty(s))
        return;
    s->next = s->next->next;
}

int Stack_FindMin(Stack s) {
    if (!s->next)
        return s->min;
    return s->next->min;
}
