#include "CricLinkedList.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position prev;
    Position next;
};

List CreateList(void) {
    PrtToNode l = malloc(sizeof(struct Node));
    if (l == NULL) {
        // out of memory.
        return NULL;
    }
    l->element = 0;
    l->next = l;
    l->prev = l;
    return l;
}

void MakeEmpty(List l) {
    Position p = l->next;
    Position tmp;
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

int IsEmpty(List l) {
    return l->next == l;
}

int IsFirst(Position p, List l) {
    return p == l->next;
}

int IsLast(Position p, List l) {
    return p->next == l;
}

Position Header(List l) {
    return l;
}

Position First(List l) {
    return l->next;
}

Position Last(List l) {
    // Position p = l;
    // while (p->next != l)
    //     p = p->next;
    // return p;
    return l->prev;
}

inline Position Next(Position p, List l) {
    if (p->next == l) {
        return l->next;
    }
    return p->next;
}

Position Prev(Position p, List l) {
    // Position prev = l->next;
    // while (prev->next != p)
    //     prev = prev->next;
    // return prev;
    if (p->prev == l) {
        return l->prev->prev;
    }
    return p->prev;
}

void Insert(ElementType x, Position p, List l) {
    Position dest = malloc(sizeof(struct Node));
    if (dest == NULL) {
        // out of memory.
        return;
    }
    dest->element = x;
    dest->next = p->next;
    
    Position next = p->next;
    p->next = dest;
    next->prev = dest;
    dest->next = next;
    dest->prev = p;
}

void Append(ElementType x, List l) {
    Insert(x, Last(l), l);
}

Position Delete(Position p, List l) {
    Position prev = p->prev;
    Position next = p->next;
    prev->next = next;
    next->prev = prev;
    free(p);
    return prev;
}

inline ElementType Retrieve(Position p, List l) {
    return p->element;
}

inline Position Advance(Position p, List l) {
    return Next(p, l);
}
