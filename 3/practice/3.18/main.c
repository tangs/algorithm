#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

/* 
 * 1: (
 * 2: [
 * 3: {
 * 4: *
 * 1 << 8: )
 * (1 << 8) + 1: ]
 * (1 << 8) + 2: }
 * (1 << 8) + 3: *
 */
int GetNextStrType(char *str) {
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

int Check(char *str) {
    // char ch;
    Stack s = CreateStack();
    int line = 1;
    int col = 1;
    int isNote = 0;
    while (*str) {
        int ret = GetNextStrType(str);
        char type = (char)ret & 0xff;
        if (type) {
            if (ret >> 8) {
                if (!isNote || type == 4) {
                    if (IsEmpty(s)) {
                        printf("balance fail.line: %d col: %d type:%d\n", line, col, type);
                        return 1;
                    } else if (Top(s) == type) {
                        Pop(s);
                    } else {
                        printf("balance fail.line: %d col: %d type:%d\n", line, col, type);
                        return 1;
                    }
                    isNote = 0;
                }
            } else {
                if (!isNote)
                    Push(type, s);
                if (type == 4)
                    isNote = 1;
            }
        }
        if (type == 4) {
            str += 2;
            col += 2;
        } else {
            if (*str == '\n') {
                ++line;
                col = 1;
            } else {
                ++col;
            }
            ++str;
        }
    }
    if (!IsEmpty(s)) {
        printf("balance fail: type:%d\n", Top(s));
        return 1;
    }
    return 0;
}

/* (*/
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
