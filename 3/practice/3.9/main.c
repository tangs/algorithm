#include <stdio.h>
#include <limits.h>

#include "Number.h"

int PrintZore(int times, char *str, int len) {
    for (int i = 0; i < times; ++i) {
        snprintf(str++, len, "%d", 0);
    }
    return times;
}

int NumberToString(Number num, char *str, int len) {
    Position p = First(num);
    Position prev = NULL;
    int digit = -1;
    char *pStr = str;
    char tmp[NUMBER_OVERFLOWBITS];
    memset(tmp, '0', NUMBER_OVERFLOWBITS - 1);
    while (p) {
        int curDigit = Digit(p);
         if (digit != -1)
            pStr += PrintZore((digit - curDigit) * NUMBER_OVERFLOWBITS, pStr, len - (pStr - str));
        int count = snprintf(tmp, NUMBER_OVERFLOWBITS, "%d", Value(p));
        if (digit != -1)
            pStr += PrintZore(NUMBER_OVERFLOWBITS - count - 1, pStr, len - (pStr - str));
        pStr += snprintf(pStr, len - (pStr - str), "%s", tmp);
        digit = curDigit - 1;
        prev = p;
        p = Advance(p);
    }
    if (prev)
        pStr += PrintZore(Digit(prev) - 1, pStr, len - (pStr - str));
    *pStr = 0;
    return pStr - str;
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
    // PrintNumber(ret);
    const len = 1024 * 10;
    char str[len];
    int cnt = NumberToString(ret, str, len);
    int cnts[10];
    memset(cnts, 0, sizeof(int) * 10);
    for (int i = 0; i < cnt; ++i) {
        ++cnts[str[i] - '0'];
    }
    printf("%s\n", str);
    for (int i = 0; i < 10; ++i) {
        printf("%d:%d\n", i, cnts[i]);
    }
    printf("total:%d\n", cnt);

    DisposeNumber(num1);
    // DisposeNumber(num2);
    DisposeNumber(ret);
    return 0;
}
