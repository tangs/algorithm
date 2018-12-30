#include "stdio.h"

#include "def.h"
#include "StackArr.h"

int main() {
    FILE* f = fopen("./main.c", "r");
    if (f == NULL) {
        printf("Can't read file.\n");
        return 1;
    }
    Stack s = CreateStack(1024);
    char ch;
    int row = 1;
    int col = 0;
    while((ch = getc(f)) != EOF) {
        ++col;
        switch (ch) {
            case '[':
            case '(':
            case '{': {
                ElementType data;
                data.ch = ch;
                data.row = row;
                data.col = col;
                Push(data, s);
            }
            break;
            case ']':
            case ')':
            case '}': {
                if (IsEmpty(s)) {
                    printf("err1:%c row:%d col:%d\n", ch, row, col);
                    return 2;
                }
                ElementType data = Top(s);
                char ch1 = data.ch;
                if ((ch1 == '[' && ch == ']') 
                || (ch1 == '(' && ch == ')') 
                || (ch1 == '{' && ch == '}')) {
                    // printf("pop.ch:%c row:%d col:%d\n", ch, row, col);
                    Pop(s);
                } else {
                    printf("err2:%c row:%d col:%d\n", ch, row, col);
                    printf("prev:%c row:%d col:%d\n", data.ch, data.row, data.col);
                    return 3;
                }
            }
            break;
            case '\n':
                ++row;
                col = 0;
            break;
        }
    }
    printf("check result:%d\n", IsEmpty(s));
    if (!IsEmpty(s)) {
        ElementType data = Top(s);
        printf("prev:%c row:%d col:%d\n", data.ch, data.row, data.col);
    }
    DisposeStack(s);
    return 0;
}
