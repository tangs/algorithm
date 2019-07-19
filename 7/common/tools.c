#include <stdio.h>

void ShowArr(int *data, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", data[i]);
    printf("\n");
}
