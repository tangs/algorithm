#include "StackArr.h"

#include <stdlib.h>
#include <stdio.h>

struct StackRecord {
    int capacity;
    int topOfStack;
    ElementType* array;
};

Stack CreateStack(int maxElements) {
    Stack stack = malloc(sizeof(struct StackRecord));
    if (stack == NULL)
        printf("Out of space.");
    stack->topOfStack = -1;
    stack->array = malloc(sizeof(ElementType) * maxElements);
    if (stack->array == NULL)
        printf("Out of space.");
    stack->capacity = maxElements;
    return stack;
}

void DisposeStack(Stack s) {
    if (s != NULL) {
        free(s->array);
        free(s);
    }
}

int IsEmpty(Stack s) {
    return s->topOfStack == -1;
}

int IsFull(Stack s) {
    return s->topOfStack == s->capacity - 1;
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
        // return 0;
    }
    return s->array[s->topOfStack];
}

void Pop(Stack s) {
    if (IsEmpty(s)) {
        printf("Stack is empty.");
    } else {
        --(s->topOfStack);
    }
}
