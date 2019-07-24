#include "../common/tools.h"

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int Median3(int *data, int n, int s, int e) {
    // ShowArr(data, n);
    int mid = (s + e) / 2;
    if (data[s] > data[mid])
        swap(&data[s], &data[mid]);
    if (data[s] > data[e])
        swap(&data[s], &data[e]);
    if (data[mid] > data[e])
        swap(&data[mid], &data[e]);
    swap(&data[mid], &data[e - 1]);
    // ShowArr(data, n);
    return data[e - 1];
}

void QSort(int *data, int n, int s, int e) {
    if (s >= e)
        return;
    int pivot = Median3(data, n, s, e);
    int i = s;
    int j = e - 1;
    for(;;) {
        while(data[++i] < pivot);
        while(data[--j] > pivot);
        if (i < j) {
            swap(&data[i], &data[j]);
        } else {
            break;
        }
    }
    swap(&data[i], &data[e - 1]);
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
