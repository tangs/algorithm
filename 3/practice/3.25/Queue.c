#include "Queue.h"

#include <stdlib.h>

struct Queue_Node {
    ElementType element;
    Queue_Pos prev;
    Queue_Pos next;
};

Queue Queue_Create() {
    Queue q = malloc(sizeof(struct Queue_Node));
    if (!q) {
        // out of memory.
        return NULL;
    }
    q->next = q;
    q->prev = q;
    q->element = 0;
    return q;
}

void Queue_Dispose(Queue q) {
    Queue_MakeEmpty(q);
    free(q);
}

void Queue_MakeEmpty(Queue q) {
    Queue_Pos p = q->next, tmp;
    while (p != q) {
        tmp = p;
        p = p->next;
        free(p);
    }
}

int Queue_IsEmpty(Queue q) {
    return q->next == q;
}

void Queue_Enqueue(ElementType x, Queue q) {
    Queue_Pos p = malloc(sizeof(struct Queue_Node));
    if (!p) {
        // out of memory.
        return;
    }
    p->element = x;
    Queue_Pos next = q->next;
    q->next = p;
    next->prev = p;
    p->next = next;
    p->prev = q;

}

ElementType Queue_Front(Queue q) {
    if (q == q->next) {
        // queue is empty.
        return ELEMENT_ERR;
    }
    return q->prev->element;
}

void Queue_Dequeue(Queue q) {
    if (q == q->next) {
        // queue is empty.
        return;
    }
    Queue_Pos p = q->prev;
    Queue_Pos prev = q->prev;
    prev->next = q;
    q->prev = prev;
    free(p);
}

ElementType Queue_FrontAndDequeue(Queue q) {
    if (q == q->next) {
        // queue is empty.
        return ELEMENT_ERR;
    }
    Queue_Pos p = q->prev;
    Queue_Pos prev = p->prev;
    prev->next = q;
    q->prev = prev;
    ElementType element = p->element;
    free(p);
    return element;
}
