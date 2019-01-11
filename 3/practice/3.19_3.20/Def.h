#ifndef _Def_h
#define _Def_h

#define ELEMENT_TYPE_UNUSED -1
#define ELEMENT_TYPE_NUM 1
#define ELEMENT_TYPE_EXP 2
#define ELEMENT_TYPE_SYMBOL 3

#define ELEMENT_STR_LEN 256

struct Element {
    int num;
    int type;
    char str[ELEMENT_STR_LEN];
};

typedef struct Element ElementType;

#endif //_Def_h
