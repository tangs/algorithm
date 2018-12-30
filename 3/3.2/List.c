#include "List.h"

#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};

List CreatList() {
    PtrToNode node = malloc(sizeof(struct Node));
    node->next = NULL;
    return node;
    // return NULL;
}

List MakeEmpty(List l) {
    l->next = NULL;
    return l;
}

int IsEmpty(List l) {
    return l->next == NULL;
}

int IsLast(Position p, List l) {
    return p->next == NULL;
}

Position Find(ElementType x, List l) {
    Position p = l->next;
    while(p != NULL && p->element != x)
        p = p->next;
    return p;
}

Position GetLast(List l) {
    Position p = l;
    while(p->next != NULL)
        p = p->next;
    return p;
}

void Delete(ElementType x, List l) {
    Position prev = FindPrevious(x, l);
    if (!IsLast(prev, l)) {
        Position tmp = prev->next;
        prev->next = tmp->next;
        free(tmp);
    }
}

Position FindPrevious(ElementType x, List l) {
    Position prev = l;
    while(prev->next != NULL && prev->next->element != x)
        prev = prev->next;
    return prev;
}

void Insert(ElementType x, List l, Position p) {
    PtrToNode node = malloc(sizeof(struct Node));
    // if (node == NULL)
        // ;
    node->element = x;
    node->next = p->next;
    p->next = node;
}

void Append(ElementType x, List l) {
    Position p = GetLast(l);
    Insert(x, l, p);
}

void DeleteList(List l) {
    Position p, tmp;
    p = l->next;
    while(p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    l->next = NULL;
}

Position Header(List l) {
    return l;
}

Position First(List l) {
    return l->next;
}

Position Advance(Position p) {
    if (p == NULL) return NULL;
    return p->next;
}

ElementType Retrieve(Position p) {
    if (p == NULL) return 0;
    return p->element;
}

void PrintElements(List l) {
    Position p = First(l);
    while(p != NULL) {
        printf("%d ", Retrieve(p));
        p = Advance(p);
    }
    printf("\n");
}
