#ifndef _Strack_h
#define _Strack_h

#include "Def.h"

struct Node;

typedef struct Node *PtrToNode;
typedef int StackPos;
typedef PtrToNode Stack;

Stack Stack_Create(int capacity);

void Stack_MakeEmpty(Stack s, int isHead);
void Stack_Dispose(Stack s);

int Stack_IsEmpty(Stack s, int isHead);

int Stack_Push(ElementType x, Stack s, int isHead);
void Stack_Pop(Stack s, int isHead);
ElementType Stack_Top(Stack s, int isHead);
ElementType Stack_TopAndPop(Stack s, int isHead);

#endif // _Strack_h
