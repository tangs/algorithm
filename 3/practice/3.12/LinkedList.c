#include "LinkedList.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};

List CreateList(void) {
    List l = malloc(sizeof(struct Node));
    if (l == NULL) {
        // out of memory.
        return NULL;
    }
    l->element = 0;
    l->next = NULL;
    return l;
}

void DisposeList(List l) {
    Position p = l;
    Position tmp;
    while (p) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

Position First(List l) {
    return l->next;
}

void Insert(ElementType x, Position p, List l) {
    Position dest = malloc(sizeof(struct Node));
    if (dest == NULL) {
        // out of memory.
        return;
    }
    dest->element = x;
    dest->next = p->next;
    p->next = dest;
}

void Reverse(List l) {
    if (!l->next || !l->next->next) return;
    Position p1 = l->next;
    Position p2;
    Position next = p1->next;
    while (1) {
        p2 = next;
        next = p2->next;
        p2->next = p1;
        if (!next) {
            l->next->next = NULL;
            l->next = p2;
            break;
        }
        p1 = p2;
    }
}

ElementType Retrieve(Position p, List l) {
    return p->element;
}

Position Advance(Position p, List l) {
    return p->next;
}
