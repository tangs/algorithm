#include <stdlib.h>

#include "../common/tools.h"

void Merge(int *data, int* tmpArr, int lPos, int rPos, int endPos) {
    int aPos = lPos;
    int bPos = rPos;
    int idx = 0;
    while(aPos < rPos && bPos <= endPos) {
        if (data[aPos] <= data[bPos]) {
            tmpArr[idx++] = data[aPos++];
        } else {
            tmpArr[idx++] = data[bPos++];
        }
    }

    while(aPos < rPos) {
        tmpArr[idx++] = data[aPos++];
    }

    while(bPos <= endPos) {
        tmpArr[idx++] = data[bPos++];
    }

    for (int i = 0; i < idx; ++i) {
        data[lPos + i] = tmpArr[i];
    }
}

void MSort(int* data, int* tmpArr, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        MSort(data, tmpArr, left, center);
        MSort(data, tmpArr, center + 1, right);
        Merge(data, tmpArr, left, center + 1, right);
    }
}

void MergeSort(int* data, int n) {
    int* tmpArr = malloc(sizeof(int) * n);
    if (tmpArr) {
        MSort(data, tmpArr, 0, n - 1);
        free(tmpArr);
    } else {
        // error
    }
}

int main() {
    int a[] = {1, 13, 24, 26, 2, 15, 27, 38};
    int n = GetArrLen(a);
    ShowArr(a, n);
    MergeSort(a, n);
    ShowArr(a, n);
    return 0;
}
