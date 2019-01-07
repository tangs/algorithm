#include "List.h"

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

Position Header(List l) {
    return l;
}

Position First(List l) {
    return l->next;
}

void Insert(ElementType x, Position p, List l) {
    Position p1 = malloc(sizeof(struct Node));
    if (p1 == NULL) {
        // out of memory.
        return;
    }
    p1->element = x;
    p1->next = p->next;
    p->next = p1;
}

Position FindRec(ElementType x, Position p, List l) {
    if (p == NULL || x == p->element)
        return p;
    return FindRec(x, p->next, l);
}

Position FindNRec(ElementType x, Position p, List l) {
    while (p && p->element != x)
        p = p->next;
    return p;
}

ElementType Retrieve(Position p, List l) {
    return p->element;
}
