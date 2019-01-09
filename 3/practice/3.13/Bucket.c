#include "Bucket.h"

#include <stdlib.h>
#include <math.h>

void Sort_Bucket(List l, int base, int times) {
    List *buckets = malloc(base * sizeof(List));
    for (int i = 0; i < base; ++i)
        buckets[i] = CreateList();
    
    Position p = First(l);
    while (!IsHeader(p, l)) {
        ElementType element = Retrieve(p);
        int idx = element % base;
        Append(element, buckets[idx]);
        p = Advance(p, l);
    }

    int num = base;
    for (int i = 1; i < times; ++i) {
        for (int j = 0; j < base; ++j) {
            List bucket = buckets[j];
            Position p = First(bucket);
            Position endP = NULL;
            while (!IsHeader(p, bucket) && endP != p) {
                ElementType element = Retrieve(p);
                int idx = (element / num) % base;
                p = Delete(p, bucket);
                Append(element, buckets[idx]);

                if (!endP && idx == j) {
                    endP = Last(buckets[idx]);
                }
                p = Advance(p, bucket);
            }
        }
        num *= base;
    }

    MakeEmpty(l);
    for (int i = 0; i < base; ++i) {
        List bucket = buckets[i];
        Position p = First(bucket);
        while (!IsHeader(p, bucket)) {
            ElementType element = Retrieve(p);
            Append(element, l);
            p = Advance(p, bucket);
        }
    }

    for (int i = 0; i < base; ++i)
        free(buckets[i]);
    free(buckets);
}
