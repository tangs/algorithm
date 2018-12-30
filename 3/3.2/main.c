#include <stdio.h>

#include "Cursor.h"

#include "Bucket.h"

// struct Node;

// void showList(List l) {
//     Position p = First(l);
//     while(p != NULL) {
//         printf("%d ", Retrieve(p));
//         p = Advance(p);
//     }
//     printf("\n");
// }

// 0-9999
// void sortBucket(List l) {
//     for (int i = 0; i < 4; ++i) {

//     }
// }

void func() {
    List l = CreatList();
    Insert(729, l, l);
    Insert(8, l, l);
    Insert(27, l, l);
    Insert(216, l, l);
    Insert(125, l, l);
    Insert(64, l, l);
    Insert(343, l, l);
    Insert(512, l, l);
    Insert(1, l, l);
    Insert(0, l, l);
    // PrintElements(l);
    // SortBucket(l, 3);
    SortBucket(l);
}

int main() {
    InitializeCursorSpace();
    func();
    return 0;
}