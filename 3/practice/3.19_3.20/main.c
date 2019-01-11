#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Stack.h"
#include "LinkedList.h"

struct SymbolInfo {
    char priorty;
    char rightPriority;
    char pushToDest;
    char pass;
    char dest;
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
            info.rightPriority = 0;
            break;
        break;
        case '*':
        case '/':
            info.priorty = 2;
            info.rightPriority = 0;
            break;
        case '(': 
            info.priorty = 10;
            info.rightPriority = 1;
            info.pass = 1;
            break;
        case ')':
            info.priorty = 11;
            info.rightPriority = 0;
            info.pushToDest = 1;
            info.dest = '(';
            info.pass = 1;
            break;
    }
    return info;
}

int Calc(Stack numS, Stack symbolS, List destL, char destSymbol) {
    if (IsEmpty(symbolS)) return 1;
    ElementType symbol = TopAndPop(symbolS);
    struct SymbolInfo info = GetSymbolInfo(symbol.num);
    if (info.pass) {
        if (info.dest != destSymbol)
            return Calc(numS, symbolS, destL, info.dest);
        return 0;
    }
    if (IsEmpty(numS)) return 2;
    ElementType num2 = TopAndPop(numS);
    int isFirst = List_IsEmpty(destL);
    List_Append(symbol, destL);
    List_AddToHead(num2, destL);
    if (isFirst) {
        if (IsEmpty(numS)) return 3;
        ElementType num1 = TopAndPop(numS);
        List_AddToHead(num1, destL);
    }
    return 0;
}

int InfixToPost(char *src, char *dest, int len) {
    Stack numS = CreateStack();
    Stack symbolS = CreateStack();
    List destL = List_Create();
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
            ElementType element;
            element.num = num;
            // strcpy(element.str, "%d", num);
            element.type = ELEMENT_TYPE_NUM;
            Push(element, numS);
        } else {
            len = 1;
            ElementType element;
            element.num = *pStr;
            element.type = ELEMENT_TYPE_SYMBOL;
            struct SymbolInfo info = GetSymbolInfo(*pStr);
            if (!info.priorty) goto error;
            if (IsEmpty(symbolS)) {
                Push(element, symbolS);
            } else {
                char lastSymbol = (char)Top(symbolS).num;
                struct SymbolInfo lInfo = GetSymbolInfo(lastSymbol);
                Push(element, symbolS);
                int cp = info.priorty;
                int lp = info.priorty;
                if(cp < lp || (cp == lp && !info.rightPriority)) {
                    Calc(numS, symbolS, destL, 0);
                }
            }
        }

        pStr += len;
    }
    while (!IsEmpty(symbolS)) {
        if (Calc(numS, symbolS, destL, 0))
            goto error;
    }
    ListPos p = List_First(destL);
    char *pDest = dest;
    while (!List_IsHeader(p, destL)) {
        ElementType data = List_Retrieve(p, destL);
        switch (data.type) {
            case ELEMENT_TYPE_NUM: {
                int len1 = snprintf(pDest, len - (pDest - dest), "%d ", data.num);
                pDest += len1;
            }
            break;
            case ELEMENT_TYPE_SYMBOL: {
                int len1 = snprintf(pDest, len - (pDest - dest), "%c ", data.num);
                pDest += len1;
            }
            break;
            default:
                goto error;
        }
        p = List_Advance(p, destL);
    }
    goto ret;
error:
    printf("infix to post error.\n");
ret:
    DisposeStack(numS);
    DisposeStack(symbolS);
    List_DisposeList(destL);
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
        // printf("%s=%d\n", argv[i], CalcPostExp(argv[i]));
        InfixToPost(argv[i], tmp, LEN);
        printf("src:%s\ndest:%s\nret:%d\n\n", argv[i], tmp, CalcPostExp(tmp), CalcPostExp(tmp));
    }
    return 0;
}
