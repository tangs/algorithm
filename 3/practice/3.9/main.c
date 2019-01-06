#include <stdio.h>
#include <limits.h>

#include "Number.h"

void PrintZore(int times) {
    for (int i = 0; i < times; ++i)
        printf("%d", 0);
}

void PrintNumber(Number num) {
    Position p = First(num);
    Position prev = NULL;
    int digit = 0;
    while (p) {
        int curDigit = Digit(p);
        PrintZore(digit - curDigit);
        digit = curDigit - 1;
        printf("%d", Value(p));
        prev = p;
        p = Advance(p);
    }
    if (prev)
        PrintZore(Digit(prev) - 1);
    printf("\n");
}

int main() {
    Number num1 = CreateNumber();
    AddValue(1, 2, num1);

    // Number num2 = CreateNumber();
    // AddValue(1, 2, num2);


    Number ret = Mut(num1, num1);
    for (int i = 0; i < 3998; ++i) {
        Number tmp = ret;
        ret = Mut(num1, ret);
        DisposeNumber(tmp);
    }
    PrintNumber(ret);

    DisposeNumber(num1);
    // DisposeNumber(num2);
    DisposeNumber(ret);
    return 0;
}
