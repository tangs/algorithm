#include "Stack.h"

#include <stdlib.h>
#include <string.h>

struct Node {
    int capacity;
    StackPos head;
    StackPos tail;
    ElementType* data;
};

Stack Stack_Create(int capacity) {
    int size = sizeof(struct Node);
    Stack s = malloc(size);
    if (!s) {
        // out of memory.
        return NULL;
    }
    s->capacity = capacity;
    s->data = malloc(sizeof(ElementType) * capacity);
    s->head = 0;
    s->tail = capacity - 1;
    return s;
}

void Stack_MakeEmpty(Stack s, int isHead) {
    if (isHead)
        s->head = 0;
    else
        s->tail = s->capacity - 1;
}
void Stack_Dispose(Stack s) {
    free(s->data);
    free(s);
}

int Stack_IsEmpty(Stack s, int isHead) {
    return isHead ? s->head == 0 : s->tail == s->capacity - 1;
}

int Stack_Push(ElementType x, Stack s, int isHead) {
    if (s->head > s->tail) {
        // stack is full.
        return 0;
    }
    int idx = isHead ? s->head++ : s->tail--;
    s->data[idx] = x;
    return 1;
}

void Stack_Pop(Stack s, int isHead) {
    if (Stack_IsEmpty(s, isHead))
        // stack is empty.
        return;
    isHead ? s->head-- : s->tail++;
}

ElementType Stack_Top(Stack s, int isHead) {
    if (Stack_IsEmpty(s, isHead))
        // stack is empty.
        return DEF_ELEMENT;
    int idx = isHead ? s->head - 1 : s->tail + 1;
    return s->data[idx];
}

ElementType Stack_TopAndPop(Stack s, int isHead) {
    if (Stack_IsEmpty(s, isHead))
        // stack is empty.
        return DEF_ELEMENT;
    int idx = isHead ? --s->head : ++s->tail;
    return s->data[idx];
}
