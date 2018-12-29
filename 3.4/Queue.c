#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

struct QueueRecord {
    int front;
    int rear;
    ElementType* array;
};

Queue CreateQueue(int maxElements) {
    Queue q = malloc(sizeof(struct QueueRecord));
    q->front = 0;
    q->rear = 0;
    q->array = malloc(maxElements * sizeof(int));
    return q;
}

void DisposeQueue(Queue q) {
    if (q->array)
        free(q->array);
    free(q);
}

int IsEmpty(Queue q) {
    return q->front == q->rear;
}

int IsFull(Queue q) {
    return q->front - q->rear == 1;
}

void MakeEmpty(Queue q) {
    q->front = 0;
    q->rear = 0;
}

void Enqueue(ElementType x, Queue q) {
    if (IsFull(q)) {
        printf("Enqueue fail, the queue is full.%p\n", q);
        return;
    }
    q->array[q->rear++] = x;
}

void Dequeue(Queue q) {
    if (IsEmpty(q)) {
        printf("Dequeue fail, the queue is empty.%p\n", q);
        return;
    }
    q->front++;
}

ElementType Front(Queue q) {
    if (IsEmpty(q)) {
        printf("Front fail, the queue is empty.%p\n", q);
        return 0;
    }
    return q->array[q->front];
}

ElementType FrontAndDequeue(Queue q) {
    if (IsEmpty(q)) {
        printf("Front fail, the queue is empty.%p\n", q);
        return 0;
    }
    return q->array[q->front++];
}
