#ifndef _Def_h
#define _Def_h

#define ELEMENT_TYPE_UNUSED -1
#define ELEMENT_TYPE_NUM 1
#define ELEMENT_TYPE_SYMBOL 2

struct Element {
    int num;
    int type;
};

typedef struct Element ElementType;

#endif //_Def_h
