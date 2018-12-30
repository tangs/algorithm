#include "Bucket.h"

#include <stdio.h>
#include <math.h>

#define MAX(x, y) (x > y ? x : y)

void PrintBucket(List* l, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d:", i);
        PrintElements(l[i]);
    }
    printf("\n");
}

// void SortBucket(List l, int times) {
void SortBucket(List l) {
    const int len = 8;
    List buckets[len];
    for (int i = 0; i < len; ++i)
        buckets[i] = CreatList();
    Position p = First(l);
    ElementType max = 0;
    while(p != NULL) {
        int v = Retrieve(p);
        max = MAX(v, max);
        List l = buckets[v & 7];
        Append(v, l);
        p = Advance(p);
    }
    int times = 0;
    while(max != 0) {
        max >>= 3;
        ++times;
    }
    PrintBucket(buckets, len);
    for (int i = 1; i < times; ++i) {
        for (int j = 0; j < len; ++j) {
            List l = buckets[j];
            Position p = First(l);
            while(p != NULL) {
                int v = Retrieve(p);
                p = Advance(p);
                // int idx = (v / (int)(pow(10, i))) % 10;
                int idx = (v >> (3 * i)) & 7;
                if (idx != j) {
                    Delete(v, l);
                    List l1 = buckets[idx];
                    Append(v, l1);
                }
            }
        }
        PrintBucket(buckets, len);
    }
}