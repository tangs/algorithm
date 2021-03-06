#include "ArrList.h"

#include <stdlib.h>

struct Node {
    ElementType *data;
    int capacity;
    int size;
    // Position current;
};

List CreateList(int capacity) {
    List l = malloc(sizeof(struct Node));
    if (!l) {
        // out of memory.
        return NULL;
    }
    l->data = malloc(sizeof(ElementType) * capacity);
    l->capacity = capacity;
    l->size = 0;
    // l->current = 0;
    return l;
}

void MakeEmpty(List l) {
    l->size = 0;
    // l->current = 0;
}

void DisposeList(List l) {
    free(l->data);
    free(l);
}

Position Header(List l) {
    return 0;
}

Position First(List l) {
    if (l->size)
        return 1;
    return 0;
}

void QuickSort(List l) {
    ElementType* data = l->data;
    for (int i = 1; i < l->size; ++i) {
        int tmp = data[i];
        if (tmp > data[i-1]) continue;
        int s = 0;
        int e = i - 1;
        int idx = e / 2;
        while (e > s) {
            if (tmp > data[idx]) {
                s = idx + 1;
                idx = (s + e) / 2;
            } else if (tmp < data[idx]) {
                e = idx - 1;
                idx = (s + e) / 2;
            } else {
                break;
            }
        }
        idx = tmp > data[idx] ? idx + 1 : idx;
        for (int j = i; j >= idx; j--) {
            data[j] = data[j-1];
        }
        data[idx] = tmp;
    }
}

void Insert(ElementType x, Position p, List l) {
    if (l->size == l->capacity) 
        return;
    for (int i = l->size - 1; i >= p; --i) {
        l->data[i+1] = l->data[i];
    }
    l->data[p] = x;
    l->size++;
}

void Delete(Position p, List l) {
    int idx = p - 1;
    if (idx >= l->size) return;
    for (int i = idx; i < l->size - 1; ++i)
        l->data[i] = l->data[i+1];
    l->size--;
}

void DeleteRepeat(List l) {
    for (int i = 0; i < l->size; ++i) {
        int j = i + 1;
        while (j < l->size) {
            if (l->data[i] == l->data[j]) {
                Delete(j + 1, l);
            } else {
                j++;
            }
        }
    }
}

ElementType Retrieve(Position p, List l) {
    return l->data[p-1];
}

Position Advance(Position p, List l) {
    if (p < l->size)
        return p + 1;
    return 0;
}
