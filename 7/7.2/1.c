#include <stdio.h>

typedef int ElementType;

void Swap(ElementType* a, ElementType* b) {
    ElementType c = *a;
    *a = *b;
    *b = c;
}

void InsertionSort(ElementType *data, int len) {
    for (int i = 1; i < len; ++i) {
        ElementType tmp = data[i];
        int j;
        for (j = i - 1; j >= 0 && data[j] > tmp; --j)
            data[j + 1] = data[j];
        data[j + 1] = tmp;
    }
}

void ShowArr(ElementType *data, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", data[i]);
    printf("\n");
}

int main() {
    int a[] = {34, 8, 64, 51, 32, 21};
    int len = sizeof(a) / sizeof(int);
    ShowArr(a, len);
    InsertionSort(a, len);
    ShowArr(a, len);
    return 0;
}
