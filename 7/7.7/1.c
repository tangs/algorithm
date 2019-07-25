#include "../common/tools.h"

#define Cutoff 3

void Swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void InsertionSort(int *data, int len) {
    for (int i = 1; i < len; ++i) {
        int tmp = data[i];
        int j;
        for (j = i - 1; j >= 0 && data[j] > tmp; --j)
            data[j + 1] = data[j];
        data[j + 1] = tmp;
    }
}

int Median3(int *data, int n, int s, int e) {
    // ShowArr(data, n);
    int mid = (s + e) / 2;
    if (data[s] > data[mid])
        Swap(&data[s], &data[mid]);
    if (data[s] > data[e])
        Swap(&data[s], &data[e]);
    if (data[mid] > data[e])
        Swap(&data[mid], &data[e]);
    Swap(&data[mid], &data[e - 1]);
    // ShowArr(data, n);
    return data[e - 1];
}

void QSort(int *data, int n, int s, int e) {
    if (s + Cutoff > e) {
        InsertionSort(data + s, e - s + 1);
        return;
    }
    int pivot = Median3(data, n, s, e);
    int i = s;
    int j = e - 1;
    for(;;) {
        while(data[++i] < pivot);
        while(data[--j] > pivot);
        if (i < j) {
            Swap(&data[i], &data[j]);
        } else {
            break;
        }
    }
    Swap(&data[i], &data[e - 1]);
    // ShowArr(data, n);
    QSort(data, n, s, i - 1);
    QSort(data, n, i + 1, e);
}

void QuickSort(int *data, int n) {
    QSort(data, n, 0, n - 1);
}

int main() {
    int a[] = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
    int len = GetArrLen(a);
    ShowArr(a, len);
    QuickSort(a, len);
    ShowArr(a, len);
    return 0;
}
