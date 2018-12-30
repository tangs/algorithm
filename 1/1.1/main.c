#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort1(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] < arr[j]) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

void sort2(int *arr, int len, int *newArr, int size) {
    for (int i = 0; i < size; ++i)
        newArr[i] = arr[i];
    sort1(newArr, size);
    for (int i = size; i < len; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i] > newArr[j]) {
                for (int k = size - 1; k > j; --k)
                    newArr[k] = newArr[k-1];
                newArr[j] = arr[i];
                break;
            }
        }
    }
}

int getValueByIdx(int *arr, int len, int idx) {
    printArr(arr, len);
    // sort1(arr, len);
    // printArr(arr, len);
    int size = idx + 1;
    int *newArr = malloc(size * sizeof(int));
    sort2(arr, len, newArr, size);
    printArr(newArr, size);
    int ret = newArr[idx];
    free(newArr);
    return ret;
}

int main() {
    int data[] = {43, 2, 53, 9, 63, 32, 10, 6, 3};
    int len = sizeof(data) / sizeof(int);
    printf("%d\n", getValueByIdx(data, len, 4));
    return 0;
}
