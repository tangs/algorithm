#include <stdio.h>
#include <stdlib.h>

// #include "List.h"
#include "DuLinkList.h"

void PrintElements(List l) {
    Position p = First(l);
    while (p && p != l) {
        printf("%d\n", Retrieve(p));
        p = Advance(p);
    }
}

List Intersection(List l, List p) {
    List intersection = CreateList();
    Position p1 = First(l);
    Position p2 = First(p);
    while (1) {
        if ((!p1 || p1 == l) || (!p2 || p2 == p)) break;
        ElementType value1 = Retrieve(p1);
        ElementType value2 = Retrieve(p2);
        if (value1 == value2) {
            Append(value1, intersection);
            p1 = Advance(p1);
            p2 = Advance(p2);
        } else if (value1 > value2) {
            p2 = Advance(p2);
        } else {
            p1 = Advance(p1);
        }
    }
    return intersection;
}

List Union(List l, List p) {
    List unionList = CreateList();
    Position p1 = First(l);
    Position p2 = First(p);
    while (1) {
        int isEndP1 = !p1 || p1 == l;
        int isEndP2 = !p2 || p2 == p;
        if (isEndP1 && isEndP2) {
            break;
        }
        if (isEndP1 || isEndP2) {
            Position destP = isEndP1 ? p2 : p1;
            List destL = isEndP1 ? p : l;
            while (destP && destP != destL) {
                Append(Retrieve(destP), unionList);
                destP = Advance(destP);
            }
            break;
        }
        ElementType value1 = Retrieve(p1);
        ElementType value2 = Retrieve(p2);
        if (value1 == value2) {
            Append(value1, unionList);
            p1 = Advance(p1);
            p2 = Advance(p2);
        } else if (value1 > value2) {
            Append(value2, unionList);
            p2 = Advance(p2);
        } else {
            Append(value1, unionList);
            p1 = Advance(p1);
        }
    }
    return unionList;
}

int main() {
    List l = CreateList();
    Append(0, l);
    Append(13, l);
    Append(22, l);
    Append(28, l);
    Append(40, l);
    Append(41, l);
    Append(50, l);
    Append(55, l);
    Append(58, l);

    List p = CreateList();
    Append(2, p);
    Append(22, p);
    Append(23, p);
    Append(28, p);
    Append(42, p);
    Append(44, p);
    Append(46, p);
    Append(55, p);
    Append(80, p);

    // 3.4
    List intersection = Intersection(l, p);
    printf("intersection:\n");
    PrintElements(intersection);
    DeleteList(intersection);
    free(intersection);
    printf("\n");

    // 3.5
    List unionList = Union(l, p);
    printf("union:\n");
    PrintElements(unionList);
    DeleteList(unionList);
    free(unionList);
    printf("\n");
    
    DeleteList(l);
    free(l);
    DeleteList(p);
    free(p);
    return 0;
}
