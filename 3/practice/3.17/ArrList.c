#include "ArrList.h"

#include <stdlib.h>
#include <string.h>

struct Node {
    ElementType *data;
    char *rmBits;
    int capacity;
    int size;
    int rmNum;
};

static void RmElmentsIfNeeded(List l) {
    if (l->rmNum >= l->size / 2) {
        int delNum = 0;
        for (int i = 0; i < l->size; ++i) {
            if (l->rmBits[i]) {
                ++delNum;
            } else {
                l->data[i-delNum] = l->data[i];
            }
        }
        l->size -= delNum;
        l->rmNum = 0;
        memset(l->rmBits, 0, l->capacity);
        return delNum;
    }
}

List CreateList(int capacity) {
    List l = malloc(sizeof(struct Node));
    if (!l) {
        // out of memory.
        return NULL;
    }
    l->data = malloc(capacity* sizeof(ElementType));
    l->rmBits = malloc(capacity);
    l->capacity = capacity;
    MakeEmpty(l);
    return l;
}

void MakeEmpty(List l) {
    l->size = 0;
    l->rmNum = 0;
    memset(l->rmBits, 0, l->capacity);
}

void DisposeList(List l) {
    free(l->data);
    free(l->rmBits);
    free(l);
}

int First(List l) {
    if (l->size)
        return 0;
    return POS_END;
}

void Insert(ElementType x, Position p, List l) {
    if (l->size == l->capacity) {
        // List is full.
        return;
    }
    for (int i = l->size - 1; i >= p; --i) {
        l->data[i+1] = l->data[i];
        l->rmBits[i+1] = l->rmBits[i];
    }
    l->data[p] = x;
    l->rmBits[p] = 0;
    l->size++;
}

int Delete(Position p, List l) {
    l->rmBits[p] = 1;
    ++l->rmNum;
    RmElmentsIfNeeded(l);
    return 0;
}

ElementType Retrieve(Position p, List l) {
    return l->data[p];
}

Position Advance(Position p, List l) {
    while (++p < l->size && l->rmBits[p]);
    return p < l->size ? p : POS_END;
}
