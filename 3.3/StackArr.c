#include "StackArr.h"

#include <stdlib.h>

struct StackRecord {
    int capacity;
    int topOfStack;
    ElementType* array;
};

Stack CreateStack(int maxElements) {
    Stack stack = malloc(sizeof(struct StackRecord));
    stack->capacity = maxElements;
    stack->topOfStack = -1;
    stack->array = malloc(sizeof(ElementType) * maxElements);
    return stack;
}

int IsEmpty(Stack s) {
    return s->topOfStack == -1;
}

int IsFull(Stack s) {
    return s->topOfStack == s->capacity - 1;
}

void DisposeStack(Stack s) {
    free(s->array);
    free(s);
}

void MakeEmpty(Stack s) {
    s->topOfStack = -1;
}

void Push(ElementType x, Stack s) {
    if (IsFull(s)) {
        printf("Stack is full.");
    } else {
        s->array[++(s->topOfStack)] = x;
    }
}

ElementType Top(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack is empty.");
        return 0;
    } else {
        return s->array[s->topOfStack];
    }
}

void Pop(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack is empty.");
    } else {
        --(s->topOfStack);
    }
}
