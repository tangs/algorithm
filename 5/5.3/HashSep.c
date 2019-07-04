#include "HashSep.h"

#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    ElementType element;
    Position next;
};

typedef Position List;

struct HashTbl {
    int tableSize;
    List *theLists;
};

HashTable InitializeTable(int tableSize) {
    HashTable h;
    if (tableSize < MinTableSize) {
        // Table size  too small.
        return NULL;
    }

    h = malloc(sizeof(struct HashTbl));
    if (h == NULL) {
        // out of space.
        return NULL;
    }

    h->tableSize = NextPrime(tableSize);
}
