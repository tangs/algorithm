#include "Cursor.h"

#include <stdio.h>

#define SpaceSize 40

struct Node {
    ElementType element;
    Position next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void) {
    Position p;
    p = CursorSpace[0].next;
    if (!p) {
        return 0;
    }
    CursorSpace[0].next = CursorSpace[p].next;
    return p;
}

static void CursourFree(Position p) {
    CursorSpace[p].next = CursorSpace[0].next;
    CursorSpace[0].next = p;
}

void InitializeCursorSpace(void) {
    for (int i = 0; i < SpaceSize - 1; ++i) {
        CursorSpace[i].next = i + 1;
    }
    CursorSpace[SpaceSize-1].next = 0;
}


List CreatList() {
    Position p = CursorAlloc();
    CursorSpace[p].next = 0;
    return p;
}

int IsEmpty(const List l) {
    return CursorSpace[l].next == 0;
}

int IsLast(Position p, const List l) {
    return CursorSpace[p].next == 0;
}

Position Find(ElementType x, const List l) {
    Position p  = l;
    while(p && CursorSpace[p].element != x)
        p = CursorSpace[p].next;
    return p;
}

Position GetLast(List l) {
    Position p  = l;
    while(p && CursorSpace[p].next != 0)
        p = CursorSpace[p].next;
    return p;
}

Position FindPrevious(ElementType x, const List l) {
    Position p  = l;
    if (!p) return 0;
    while(CursorSpace[p].next && CursorSpace[CursorSpace[p].next].element != x)
        p = CursorSpace[p].next;
    return p;
}

void Delete(ElementType x, List l) {
    Position p = FindPrevious(x, l);
    if (!IsLast(p, l)) {
        Position tmp = CursorSpace[p].next;
        CursorSpace[p].next = CursorSpace[tmp].next;
        CursourFree(tmp);
    }
}

void Insert(ElementType x, List l, Position p) {
    Position p1 = CursorAlloc();
    if (p1 == 0) {
        return;
    }
    CursorSpace[p1].element = x;
    CursorSpace[p1].next = CursorSpace[p].next;
    CursorSpace[p].next = p1;
}

void Append(ElementType x, List l) {
    Position p = GetLast(l);
    Insert(x, l, p);
}

void DeleteList(List l) {
    // TODO
}

Position Header(const List l) {
    return l;
}

Position First(const List l) {
    return CursorSpace[l].next;
}

Position Advance(const Position p) {
    return CursorSpace[p].next;
}

ElementType Retrieve(const Position p) {
    return CursorSpace[p].element;
} 

void PrintElements(List l) {
    Position p = First(l);
    while(p != NULL) {
        printf("%o ", Retrieve(p));
        p = Advance(p);
    }
    printf("\n");
}
