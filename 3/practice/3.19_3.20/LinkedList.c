#include "LinkedList.h"

#include <stdlib.h>

struct ListNode {
    ElementType element;
    ListPos prev;
    ListPos next;
};

List List_Create() {
    List l = malloc(sizeof(struct ListNode));
    if (!l) {
        // out of memory.
        return NULL;
    }
    l->element.type = ELEMENT_TYPE_UNUSED;
    l->prev = l;
    l->next = l;
    return l;
}

void List_MakeEmpty(List l) {
    ListPos p = l->next, tmp;
    while (p != l) {
        tmp = p;
        p = p->next;
        free(p);
    }
    p->next = p;
    p->prev = p;
}

void List_DisposeList(List l) {
    List_MakeEmpty(l);
    free(l);
}

ListPos List_Header(List l) {
    return l;
}

ListPos List_First(List l) {
    return l->next;
}

int List_IsEmpty(List l) {
    return l == l->next;
}

int List_IsHeader(List l) {
    return l == l->next;
}

static void List_Insert(ListPos pos, ElementType element, List l) {
    ListPos p = malloc(sizeof(struct ListNode));
    if (!p) {
        // out of memory.
        return;
    }
    p->element = element;
    ListPos prev = pos->prev;
    ListPos next = pos->next;
    prev->next = p;
    next->prev = p;
    p->next = next;
    p->prev = prev;
}

void List_Append(ElementType element, List l) {
    List_Insert(l->prev, element, l);
}

void List_AddToHead(ElementType element, List l) {
    List_Insert(l, element, l);
}

ElementType List_Retrieve(ListPos p, List l) {
    return l->element;
}

ListPos List_Advance(ListPos p, List l) {
    return l->next;
}
