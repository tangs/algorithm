#include "LinkedList.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position prev;
    Position next;
};

List CreateList(void) {
    List l = malloc(sizeof(struct Node));
    if (!l) {
        // out of memory.
        return NULL;
    }
    l->element = 0;
    l->prev = l;
    l->next = l;
    return l;
}

void MakeEmpty(List l) {
    Position p = l->next, tmp;
    while (p != l) {
        tmp = p;
        p = p->next;
        free(p);
    }
}

void DisposeList(List l) {
    MakeEmpty(l);
    free(l);    
}

Position Header(List l) {
    return l;
}

Position First(List l) {
    return l->next;
}

void Add(ElementType x, List l) {
    Position p = malloc(sizeof(struct Node));
    if (!p) {
        // out of memory.
        return;
    }
    p->element = x;
    p->next = l->next;
    p->prev = l;
    l->next->prev = p;
    l->next = p;
}

Position Find(ElementType x, List l) {
    Position p = l->next;
    while (p != l && p->element != x)
        p = p->next;
    if (p != l && p != l->next) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = l->next;
        p->prev = l;
        l->next->prev = p;
        l->next = p;
    }
    return p != l ? p : NULL;
}

ElementType Retrieve(Position p) {
    return p->element;
}

Position Advance(Position p, List l) {
    return p->next;
}
