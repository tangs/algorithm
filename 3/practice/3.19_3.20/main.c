#include <stdio.h>
#include <math.h>

#include "Stack.h"

int GetNumber(char *str, int *pNum) {
    *pNum = 0;
    char* pStr = str;
    while (*pStr) {
        int num = *pStr - '0';
        if (num >= 0 && num <= 9) {
            *pNum = *pNum * 10 + num;
        } else {
            break;
        }
        ++pStr;
    }
    return pStr - str;
}

int CalcPostExp(char *str) {
    int ret = 0;
    Stack s = CreateStack();
    char *pStr = str;
    while (*pStr) {
        if (*pStr == ' ') {
            pStr++;
            continue;
        }
        int num;
        int len = GetNumber(pStr, &num);
        if (len > 0) {
            Push(num, s);
        } else {
            if (IsEmpty(s)) goto error;
            int num2 = TopAndPop(s);
            if (IsEmpty(s)) goto error;
            int num1 = TopAndPop(s);
            int num = 0;
            switch (*pStr) {
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
                    num = pow(num1, num2);
                break;
                default:
                    printf("err symbol %c.\n", *pStr);
                goto error;
            }
            Push(num, s);
            len = 1;
        }
        pStr += len;
    } 
    if (IsEmpty(s)) goto error;
    ret = TopAndPop(s);
    goto ret;
error:
    printf("err.\n");
ret:
    DisposeStack(s);
    return ret;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        printf("%s=%d\n", argv[i], CalcPostExp(argv[i]));
    }
    return 0;
}
