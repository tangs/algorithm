#include "Deque.h"

#include <stdlib.h>

struct Deque_Node {
    ElementType element;
    Deque_Pos prev;
    Deque_Pos next;
};

Deque Deque_Create(void) {
    Deque d = malloc(sizeof(struct Deque_Node));
    if (!d) {
        // out of memory.
        return NULL;
    }
    d->element = 0;
    d->prev = d;
    d->next = d;
    return d;
}

void Deque_Dispose(Deque d) {
    Deque_MakeEmpty(d);
    free(d);
}

void Deque_MakeEmpty(Deque d) {
    Deque_Pos p = d->next, tmp;
    while (p != d) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int Deque_IsEmpty(Deque d) {
    return d == d->next;
}

static void Insert(ElementType x, Deque_Pos prev, Deque d) {
    Deque_Pos p = malloc(sizeof(struct Deque_Node));
    if (!p) {
        // out of memory.
        return;
    }
    p->element = x;
    Deque_Pos next = prev->next;
    p->prev = prev;
    p->next = next;
    prev->next = p;
    next->prev = p;
}

static ElementType GetAndDelete(Deque_Pos p, Deque d) {
    if (Deque_IsEmpty(d)) {
        // deque is empty.
        return ELEMENT_ERR;
    }
    Deque_Pos prev = p->prev;
    Deque_Pos next = p->next;
    ElementType element = p->element;
    prev->next = next;
    next->prev = prev;
    free(p);
    return element;
} 

void Deque_Push(ElementType x, Deque d) {
    Insert(x, d, d);
}

ElementType Deque_Pop(Deque d) {
    return GetAndDelete(d->next, d);
}

void Deque_Inject(ElementType x, Deque d) {
    Insert(x, d->prev, d);
}

ElementType Deque_Eject(Deque d) {
    return GetAndDelete(d->prev, d);
}
