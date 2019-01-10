#include "ArrList.h"

#include <stdlib.h>

#define SPACE_SIZE 100

struct Node {
    ElementType element;
    Position next;
};

struct Node CursorSpace[SPACE_SIZE];

static Position CursorAlloc(void) {
    Position p = CursorSpace[0].next;
    CursorSpace[0].next = CursorSpace[p].next;
    return p;
}

static void CursorFree(Position p) {
    CursorSpace[p].next = CursorSpace[0].next;
    CursorSpace[0].next = p;
}

void InitializeCursorSpace(void) {
    for (int i = 0; i < SPACE_SIZE - 1; ++i)
        CursorSpace[i].next = (i + 1) % SPACE_SIZE;
}

List CreateList(void) {
    List l = CursorAlloc();
    CursorSpace[l].next = 0;
    return l;
}

void MakeEmpty(List l) {
    CursorSpace[l].next = 0;
}

int IsFirst(Position p, List l) {
    return p == CursorSpace[l].next;
}

int IsLast(Position p, List l ) {
    return CursorSpace[p].next == p;
}

void Add(ElementType x, List l) {
    Position p = CursorAlloc();
    if (!p) {
        // out of memory.
        return;
    }
    CursorSpace[p].element = x;
    CursorSpace[p].next = CursorSpace[l].next;
    CursorSpace[l].next = p;
}

Position First(List l) {
    return CursorSpace[l].next;
}

Position Find(ElementType x, List l) {
    Position p = First(l);
    Position prev = l;
    while (p && CursorSpace[p].element != x) {
        prev = p;
        p = CursorSpace[p].next;
    }
    if (p && prev != l) {
        CursorSpace[prev].next = CursorSpace[p].next;
        CursorSpace[p].next = CursorSpace[l].next;
        CursorSpace[l].next = p;
    }
    return p;
}

ElementType Retrieve(Position p) {
    return CursorSpace[p].element;
}

Position Advance(Position p, List l) {
    return CursorSpace[p].next;
}
