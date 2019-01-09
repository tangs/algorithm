#include "Bucket.h"

#include <stdlib.h>
#include <math.h>

void BucketsToList(List* buckets, int num, List l) {
    MakeEmpty(l);
    for (int i = 0; i < num; ++i) {
        List bucket = buckets[i];
        Position p = First(bucket);
        while (!IsHeader(p, bucket)) {
            ElementType element = Retrieve(p);
            Append(element, l);
            p = Advance(p, bucket);
        }
        MakeEmpty(bucket);
    }
}

void Sort_Bucket(List l, int base, int times) {
    List *buckets = malloc(base * sizeof(List));
    for (int i = 0; i < base; ++i)
        buckets[i] = CreateList();
    
    int num = base;
    for (int i = 0; i < times; ++i) {
        Position p = First(l);
        while (!IsHeader(p, l)) {
            ElementType element = Retrieve(p);
            int idx = (element / num) % base;
            Append(element, buckets[idx]);
            p = Advance(p, l);
        }
        BucketsToList(buckets, base, l);
        num *= base;
    }

    for (int i = 0; i < base; ++i)
        free(buckets[i]);
    free(buckets);
}
