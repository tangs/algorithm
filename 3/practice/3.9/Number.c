#include "Number.h"

#include <stdlib.h>

struct Node {
    int digit;
    int value;
    PrtToNode next;
};

Number CreateNumber(void) {
    Number num = malloc(sizeof(struct Node));
    if (num == NULL) {
        // out of memory.
        return NULL;
    }
    num->digit = 0;
    num->value = 0;
    num->next = NULL;
    return num;
}

void DisposeNumber(Number num) {
    Position tmp;
    while (num) {
        tmp = num;
        num = num->next;
        free(tmp);
    }
}

Position Header(Number num) {
    return num;
}

Position First (Number num) {
    return num->next;
}

void SetValue(int digit, int value, Number num) {
    Position p = First(num);
    while (p && p->digit < digit)
        p = p->next;
    if (p->digit == digit) {
        p->value = value;
    } else {
        Position p1 = malloc(sizeof(struct Node));
        if (p1 == NULL) {
            // out of memory.
            return;
        }
        p1->digit = digit;
        p1->value = value;
        p1->next = p->next;
        p->next = p1;
    }
}

void AddValue(int digit, int value, Number num) {
    Position p = GetPostion(digit, num);
    int dest = p->value + value;
    if (dest < 0) {
        p->value = dest + 10;
        AddValue(digit - 1, -1, num);
    } else if (dest < 10) {
        p->value = dest;
    } else {
        p->value = dest % 10;
        AddValue(digit + 1, 1, num);
    }
}

int Digit(Number num) {
    return num->digit;
}

int Value(Number num) {
    return num->value;
}

Position GetPostion(int digit, Number num) {
    Position p = First(num);
    while (p && p->digit < digit)
        p = p->next;
    if (p->digit != digit) {
        Position p1 = malloc(sizeof(struct Node));
        if (p1 == NULL) {
            // out of memory.
            return NULL;
        }
        p1->digit = digit;
        p1->value = 0;
        p1->next = p->next;
        p->next = p1;
    }
    return p;
}

Number Add(Number num1, Number num2) {
    Number ret = CreateNumber();
    if (ret == NULL) {
        return NULL;
    }
    Position p = First(num1);
    while (p) {
        AddValue(p->digit, p->value, ret);
        p = p->next;
    }
    p = First(num2);
    while (p) {
        AddValue(p->digit, p->value, ret);
        p = p->next;
    }
    return ret;
}

Number Sub(Number num1, Number num2) {

}

Number Mut(Number num1, Number num2) {
    Number ret = CreateNumber();
    if (ret == NULL) {
        return NULL;
    }
    Position p1 = First(num1);
    Position p2 = First(num2);
    while (p1) {
        while (p2) {
            int digit = Digit(num1) + Digit(num2) - 1;
            int value = Value(num1) * Value(num2);
            AddValue(digit, value % 10, ret);
            if (value > 10) {
                AddValue(digit + 1, value / 10, ret);
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return ret;
}

Number Div(Number num1, Number num2) {

}

Position Advance(Number num) {
    return num->next;
}
