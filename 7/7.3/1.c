#include <stdio.h>

#include "../common/tools.h"

void ShellSort(int *data, int n) {
    for (int increment = n / 2; increment > 0; increment /= 2) {
        for (int i = 1; i < n; ++i) {
            int tmp = data[i];
            int j = i;
            for (; j >= increment && data[j - increment] > tmp; j -= increment) {
                data[j] = data[j - increment];
            }
            data[j] = tmp;
        }
    }
}

int main() {
    int data[] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15};
    int n = GetArrLen(data);
    ShowArr(data, n);
    ShellSort(data, n);
    ShowArr(data, n);
    return 0;
}
