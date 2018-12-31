#include "List.h"

#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};

List CreateList(void) {
    List l = malloc(sizeof(struct Node));
    if (l == NULL) {
        // "Out of memory."
        return NULL;
    }
    l->element = DEF_ELEMENT_VALUE;
    l->next = NULL;
    return l;
}

void DeleteList(List l) {
    Position p = l->next, tmp;
    l->next = NULL;
    while(p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

int IsEmpty(List l) {
    return l->next == NULL;
}

int IsLast(Position p, List l) {
    return p->next == NULL;
}

Position Find(ElementType x, List l) {
    Position p = l->next;
    while (p != NULL && p->element != x)
        p = p->next;
    return p;
}

Position FindPrevious(ElementType x, List l) {
    Position p = l;
    while (l->next != NULL && l->next->element != x) {
        p = p->next;
    }
    return p;
}

Position GetLast(List l) {
    Position p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}

void Insert(ElementType x, List l, Position p) {
    Position tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        // Out of memory.
        return;
    }
    tmp->element = x;
    tmp->next = p->next;
    p->next = tmp;
}

void Append(ElementType x, List l) {
    Insert(x, l, GetLast(l));
}

void Delete(ElementType x, List l) {
    Position p = FindPrevious(x, l);
    Position tmp = p->next;
    if (tmp != NULL) {
        p->next = tmp->next;
        free(tmp);
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
