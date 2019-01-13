#include "ArrQueue.h"

#include <stdlib.h>

struct Queue_Node {
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *data;
};

Queue Queue_Create(int capacity) {
    Queue q = malloc(sizeof(struct Queue_Node));
    if (!q) {
        // out of memory.
        return NULL;
    }
    q->data = malloc(sizeof(ElementType) * capacity);
    if (!q->data) {
        free(q);
        // out of memory.
        return NULL;
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return q;
}

void Queue_Dispose(Queue q) {
    free(q->data);
    free(q);
}

void Queue_MakeEmpty(Queue q) {
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}

int Queue_IsEmpty(Queue q) {
    return !q->size;
}

void Queue_Enqueue(ElementType x, Queue q) {
    if (q->size == q->capacity) {
        // stack is full.
        return;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % q->capacity;
    ++q->size;
}

ElementType Queue_Front(Queue q) {
    if (!q->size) {
        // queue is empty.
        return ELEMENT_ERR;
    }
    return  q->data[q->front];
}
void Queue_Dequeue(Queue q) {
    if (!q->size) {
        // queue is empty.
        return;
    }
    q->front = (q->front + 1) % q->capacity;
    --q->size;
}

ElementType Queue_FrontAndDequeue(Queue q) {
    if (!q->size) {
        // queue is empty.
        return ELEMENT_ERR;
    }
    ElementType element = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    --q->size;
    return element;
}
