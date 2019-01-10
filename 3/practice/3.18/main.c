#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

/* 
 * 1: (
 * 2: [
 * 3: {
 * 4: / *
 * 1 << 8: )
 * (1 << 8) + 1: ]
 * (1 << 8) + 2: }
 * (1 << 8) + 3: * /
 */
int GetNextStrType(char *str, int lastType) {
    switch(*str) {
        case '(':
            return 1;
        case '[':
            return 2;
        case '{':
            return 3;
        case '/':
            if (*(str+1) == '*')
                return 4;
            return 0;
        case '\'':
            if (lastType == 5)
                return (1 << 8) + 5;
            return 5;
        case '\"':
            if (lastType == 6)
                return (1 << 8) + 6;
            return 6;
        case ')':
            return (1 << 8) + 1;
        case ']':
            return (1 << 8) + 2;
        case '}':
            return (1 << 8) + 3;
        case '*':
            if (*(str+1) == '/')
                return (1 << 8) + 4;
            return 0;
        default:
            return 0;
    }
}

ElementType GetElement(int type, int row, int col) {
    ElementType data;
    data.type = type;
    data.row = row;
    data.col = col;
    switch (type) {
        case 1:
        case 2:
        case 3:
            data.priorty = 1;
            data.strLen = 1;
        break;
        case 4:
            data.priorty = 4;
            data.strLen = 2;
        break;
        case 5:
            data.priorty = 2;
            data.strLen = 1;
        break;
        case 6:
            data.priorty = 3;
            data.strLen = 1;
        break;
    }
    return data;
}

int Check(char *str) {
    // char ch;
    Stack s = CreateStack();
    int row = 1;
    int col = 1;
    // int isNote = 0;
    while (*str) {
        int lastType = IsEmpty(s) ? -1 : Top(s).type;
        int ret = GetNextStrType(str, lastType);
        char type = (char)ret & 0xff;
        int strLen = 1;
        if (type) {
            ElementType data = GetElement(type, row, col);
            if (ret >> 8) {
                if (IsEmpty(s)) {
                    printf("balance fail1.line: %d col: %d type:%d\n", row, col, type);
                    return 1;
                } else if (Top(s).type == type) {
                    Pop(s);
                } else if (Top(s).priorty <= data.priorty){
                    printf("balance fail2.line: %d col: %d type:%d\n", row, col, type);
                    return 1;
                }
            } else {
                if (IsEmpty(s) || Top(s).priorty <= data.priorty)
                    Push(data, s);
            }
            strLen = data.strLen;
        }
        if (*str == '\n') {
            ++row;
            col = 1;
        } else if (*str == '\\' && *(str+1)) {
            strLen = 2;
            col += strLen;
        } else {
            col += strLen;
        }
        str += strLen;
    }
    if (!IsEmpty(s)) {

        printf("balance fail3.line: %d col: %d type:%d\n", Top(s).row, Top(s).col, Top(s).type);
        return 1;
    }
    return 0;
}

int BalanceCheck(char* path) {
    FILE* pFile = fopen(path, "r");
    if (!pFile) {
        printf("Can't open file:%s\n", path);
        return 1;
    }
    fseek(pFile, 0, SEEK_END);
    size_t fSize = ftell(pFile);
    rewind(pFile);
    char *buffer = malloc(sizeof(char) * fSize);
    size_t result = fread(buffer, 1, fSize, pFile);
    if (result != fSize) {
        printf("Read file error.\n");
    } else {
        printf("check %s ret:%d.\n", path, Check(buffer));
    }
    fclose(pFile);
    free(buffer);
    return 0;
}

int main(int argc, char** argv) {
    for (int i = 1; i< argc; ++i)
        BalanceCheck(argv[i]);
    return 0;
}
