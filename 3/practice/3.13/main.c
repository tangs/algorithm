#include <stdio.h>

#include "Bucket.h"

void ShowList(List l, int cmp) {
    Position p = First(l);
    ElementType last = 0;
    while (!(IsHeader(p, l))) {
        ElementType element = Retrieve(p);
        printf("%d ", element);
        p = Advance(p, l);
        if (cmp && last > element) {
            printf("\nerr\n");
        }
        last = element;
    }
    printf("\n");
}

int main() {
    List l = CreateList();
    for (int i = 0; i < 1000; ++i) {
        ElementType x = rand() % 1000000000;
        // printf("%d ", x);
        Append(x, l);
    }
    // printf("\n");
    printf("before sort.\n");
    ShowList(l, 0);
    Sort_Bucket(l, 1000, 3);
    printf("after sort.\n");
    ShowList(l, 1);
    DisposeList(l);
    return 0;
}
