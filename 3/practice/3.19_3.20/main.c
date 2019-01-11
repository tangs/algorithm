#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Stack.h"

#define SYMBOL_BIT_RPRI         1       // 1 << 0
#define SYMBOL_BIT_PAREN        2       // 1 << 1
#define SYMBOL_BIT_IMM_EXE      4       // 1 << 2

struct SymbolInfo {
    char priorty;
    char pushToSymbol;
    char bits;
};

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

struct SymbolInfo GetSymbolInfo(char symbol) {
    struct SymbolInfo info;
    memset(&info, 0, sizeof(struct SymbolInfo));
    switch (symbol) {
        case '+':
        case '-':
            info.priorty = 1;
            break;
        break;
        case '*':
        case '/':
            info.priorty = 2;
            break;
        case '^':
            info.priorty = 3;
            info.bits |= SYMBOL_BIT_RPRI;
            break;
        case '(': 
            info.priorty = 10;
            info.bits |= SYMBOL_BIT_RPRI;
            info.bits |= SYMBOL_BIT_PAREN;
            break;
        case ')':
            info.priorty = 11;
            info.pushToSymbol = '(';
            info.bits |= SYMBOL_BIT_IMM_EXE;
            info.bits |= SYMBOL_BIT_PAREN;
            break;
    }
    return info;
}

int Calc(Stack numS, Stack symbolS) {
    if (IsEmpty(symbolS)) 
        return 1;
    ElementType symbol = TopAndPop(symbolS);
    struct SymbolInfo info = GetSymbolInfo(symbol.symbol);
    if (info.bits & SYMBOL_BIT_PAREN) {
        return 0;
    }
    if (IsEmpty(numS)) 
        return 2;
    ElementType num2 = TopAndPop(numS);
    if (IsEmpty(numS)) 
        return 3;
    ElementType num1 = TopAndPop(numS);
    ElementType data;
    data.type = ELEMENT_TYPE_EXP;
    snprintf(data.str, ELEMENT_STR_LEN, "%s %s %c", num1.str, num2.str, (char)symbol.symbol);
    Push(data, numS);
    return 0;
}

int InfixToPost(char *src, char *dest, int len) {
    Stack numS = CreateStack();
    Stack symbolS = CreateStack();
    int ret = 0;
    char *pStr = src;
    while (*pStr) {
        if (*pStr == ' ') {
            pStr++;
            continue;
        }
        int len = 1;
        int num;
        len = GetNumber(pStr, &num);
        if (len) {
            ElementType data;
            snprintf(data.str, ELEMENT_STR_LEN, "%d", num);
            data.type = ELEMENT_TYPE_EXP;
            Push(data, numS);
        } else {
            len = 1;
            ElementType element;
            element.symbol = *pStr;
            element.type = ELEMENT_TYPE_SYMBOL;
            struct SymbolInfo info = GetSymbolInfo(*pStr);
            if (!info.priorty) 
                goto error;
            int isImmExe = info.bits & SYMBOL_BIT_IMM_EXE;
            int isRPrior = info.bits & SYMBOL_BIT_RPRI;
            int cp = info.priorty;
            while (!IsEmpty(symbolS)) {
                char lastSymbol = (char)Top(symbolS).num;
                struct SymbolInfo lInfo = GetSymbolInfo(lastSymbol);
                int lIsParen = lInfo.bits & SYMBOL_BIT_PAREN;
                int lp = lInfo.priorty;
                if (isImmExe || (!lIsParen && (cp < lp || (cp == lp && !isRPrior)))) {
                    Calc(numS, symbolS);
                    if (lastSymbol == info.pushToSymbol)
                        break;
                } else {
                    break;
                }
            }
            if (!isImmExe)
                Push(element, symbolS);
        }

        pStr += len;
    }
    while (!IsEmpty(symbolS)) {
        if (Calc(numS, symbolS))
            goto error;
    }
    if (IsEmpty(numS)) {
        goto error;
    }
    ElementType data = TopAndPop(numS);
    strcpy(dest, data.str);
    goto ret;
error:
    printf("infix to post error.\n");
ret:
    DisposeStack(numS);
    DisposeStack(symbolS);
    return ret;
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
            ElementType element;
            element.num = num;
            element.type = ELEMENT_TYPE_NUM;
            Push(element, s);
        } else {
            len = 1;
            if (IsEmpty(s)) goto error;
            int num2 = TopAndPop(s).num;
            if (IsEmpty(s)) goto error;
            int num1 = TopAndPop(s).num;
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
            ElementType element;
            element.num = num;
            Push(element, s);
        }
        pStr += len;
    } 
    if (IsEmpty(s)) goto error;
    ret = TopAndPop(s).num;
    goto ret;
error:
    printf("err.\n");
ret:
    DisposeStack(s);
    return ret;
}

int main(int argc, char **argv) {
    const int LEN = 512;
    char tmp[LEN];
    for (int i = 1; i < argc; i++) {
        InfixToPost(argv[i], tmp, LEN);
        printf("src:%s\ndest:%s\nret:%d\n\n", argv[i], tmp, CalcPostExp(tmp));
    }
    return 0;
}
