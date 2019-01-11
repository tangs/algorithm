#ifndef _Strack_h
#define _Strack_h

#include "Def.h"

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode StackPos;
typedef PtrToNode Stack;

Stack Stack_Create(int capacity);
Stack Stack_GetTail(Stack s);

void Stack_MakeEmpty(Stack s);
void Stack_Dispose(Stack s);

void Stack_Push(ElementType x, Stack s);
void Stack_Pop(Stack s);
ElementType Top(Stack s);
ElementType TopAndPop(Stack s);

#endif // _Strack_h
