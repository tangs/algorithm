#include "Calculator.h"

#include <stdio.h>
#include <math.h>

#include "StackArr.h"

int getPriority(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

ElementType readNum(const char* str, ElementType* pNum) {
    ElementType num = 0;
    char* p = (char*)str;
    while(*p && *p >= '0' && *p <= '9') {
        num = num * 10 + (*p - '0');
        ++p;
    }
    *pNum = num;
    return p - str;
}

ElementType calcNum(Stack numS, Stack signedS) {
    if (IsEmpty(signedS)) {
        return 0;
    }
    ElementType sig = TopAndPop(signedS);
    ElementType num2 = TopAndPop(numS);
    ElementType num1 = TopAndPop(numS);
    ElementType num = 0;
    switch(sig) {
        case '+':
            num = num1 + num2;
        break;
        case '-':
            num = num1 - num2;
        break;
        case '*':
            num = num1 * num2;
        break;
        case '/':
            num = num1 / num2;
        break;
        case '^':
            num = (ElementType)pow(num1, num2);
        break;
    }
    Push(num, numS);
    return 1;
}

ElementType calc(const char* str) {
    Stack numS = CreateStack(128);
    Stack signedS = CreateStack(128);
    int idx = 0;
    int sign = 1;
    while (1) {
        char ch = str[idx++];
        if (ch == 0) break;
        if (ch == ' ') continue;
        if (ch >= '0' && ch <= '9') {
            ElementType num = 0;
            --idx;
            idx += readNum(str + idx, &num);
            Push(num * sign, numS);
            sign = 1;
        } else {
            if (ch == '(') {
                Push(ch, signedS);
            } else if (ch == ')') {
                while (Top(signedS) != '(')
                    calcNum(numS, signedS);
                Pop(signedS);
            } else {
                if (ch == '-') {
                    if (idx == 1 || str[idx-2] < '0' || str[idx-2] > '9') {
                        sign = -1;
                        continue;
                    }
                }
                while (!IsEmpty(signedS) 
                    && Top(signedS) != '(' 
                    && getPriority(ch) <= getPriority(Top(signedS))) {
                    calcNum(numS, signedS);
                }
                Push(ch, signedS);
            }
        }
    }

    while (calcNum(numS, signedS));
    int ret = 0;
    if (!IsEmpty(numS)) {
        ret = TopAndPop(numS);
    }
    DisposeStack(numS);
    DisposeStack(signedS);
    return ret;
}
