#ifndef _Stack_h
#define _Stack_h

#include "def.h"

struct StackRecord;
typedef struct StackRecord *Stack;

// typedef int ElementType;

Stack CreateStack(int maxElements);
void DisposeStack(Stack s);
int IsEmpty(Stack s);
int IsFull(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);
ElementType TopAndPop(Stack s);

#endif // _Stack_h
