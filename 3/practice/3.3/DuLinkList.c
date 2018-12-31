#include "DuLinkList.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position prev;
    Position next;
};

List CreateList(void) {
    List p = malloc(sizeof(struct Node));
    if (p == NULL) {
        // out of memory
        return NULL;
    }
    p->element = DEF_ELEMENT_VALUE;
    p->prev = p->next = p;
    return p;
}

void DeleteList(List l) {
    Position p = l->next, tmp;
    while (p != l) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int IsEmpty(List l) {
    return l->prev == l;
}

int IsLast(Position p, List l) {
    return p->next == l;
}

Position Find(ElementType x, List l) {
    Position p = l->next;
    while (p != l && p->element != x)
        p = p->next;
    return p->element == x ? p : NULL; 
}

Position FindPrevious(ElementType x, List l) {
    Position p = Find(x, l);
    return p ? p->prev : NULL;
}

Position GetLast(List l) {
    return l->prev;
}

void Insert(ElementType x, List l, Position p) {
    Position tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        // out of memory
        return;
    }
    Position next = p->next;
    tmp->element = x;

    tmp->next = next;
    tmp->prev = p;

    next->prev = tmp;
    p->next = tmp;
}

void Append(ElementType x, List l) {
    Insert(x, l, GetLast(l));
}

void Delete(ElementType x, List l) {
    Position p = Find(x, l);
    if (p) {
        Position next = p->next;
        Position prev = p->prev;
        next->prev = prev;
        prev->next = next;
        free(p);
    }
}

void Swap(ElementType x1, ElementType x2, List l) {
    Position p1 = Find(x1, l);
    Position p2 = Find(x2, l);
    if (p1 && p2) {
        Position p1Prev = p1->prev;
        Position p1Next = p1->next;
        Position p2Prev = p2->prev;
        Position p2Next = p2->next;

        p1Prev->next = p2;
        p1Next->prev = p2;
        p2->prev = p1Prev;
        p2->next = p1Next;

        p2Prev->next = p1;
        p2Next->prev = p1;
        p1->prev = p2Prev;
        p1->next = p2Next;

        if (p1->prev == p1) {
            p1->prev = p2;
            p2->next = p1;
        } else if (p1->next == p1) {
            p1->next = p2;
            p2->prev = p1;
        }
    }
}

Position Header(List l) {
    return l;
}

Position First(List l) {
    return l->next;
}

Position Advance(Position p) {
    return p->next;
}

ElementType Retrieve(Position p) {
    return p->element;
}
