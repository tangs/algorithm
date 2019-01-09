#include "LinkedList.h"

#include <stdlib.h>
#include <string.h>

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
    l->next = l;
    l->prev = l;
    return l;
}

void MakeEmpty(List l) {
    Position p = l->next, tmp;
    while (p != l) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    l->next = l;
    l->prev = l;
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

Position Last(List l) {
    return l->prev;
}

int IsHeader(Position p, List l) {
    return p == l;
}

int IsFirst(Position p, List l) {
    return p == l->next;
}

int IsLast(Position p, List l) {
    return p->next == l;
}

void Insert(ElementType x, Position p, List l) {
    Position pNew = malloc(sizeof(struct Node));
    if (!pNew) {
        // out of memory.
        return;
    }
    pNew->element = x;

    Position next = p->next;
    pNew->next = next;
    pNew->prev = p;
    next->prev = pNew;
    p->next = pNew;
}

void Append(ElementType x, List l) {
    Insert(x, l->prev, l);
}

Position Delete(Position p, List l) {
    Position prev = p->prev;
    Position next = p->next;
    prev->next = next;
    next->prev = prev;
    free(p);
    return prev;
}

ElementType Retrieve(Position p) {
    return p->element;
}

Position Advance(Position p, List l) {
    // if (p->next == l)
    //     return l->next;
    return p->next;
}
