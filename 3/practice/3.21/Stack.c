#include "Stack.h"

#include <stdlib.h>
#include <string.h>

struct Node {
    int capacity;
    int headSize;
    int tailSize;
    ElementType* data;
    StackPos tail;
};

Stack Stack_Create(int capacity) {
    int size = sizeof(struct Node);
    Stack s = malloc(size);
    if (!s) {
        // out of memory.
        return NULL;
    }
    memset(s, 0, size);
    s->capacity = capacity;
    s->data = malloc(sizeof(ElementType) * capacity);
    return s;
}

Stack Stack_GetTail(Stack s);

void Stack_MakeEmpty(Stack s);
void Stack_Dispose(Stack s);

void Stack_Push(ElementType x, Stack s);
void Stack_Pop(Stack s);
ElementType Top(Stack s);
ElementType TopAndPop(Stack s);
