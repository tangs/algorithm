#ifndef _Stack_h
#define _Stack_h

#include "Def.h"

struct Stack_Node;

typedef struct Stack_Node* PtrToNode;
typedef PtrToNode StackPos;
typedef PtrToNode Stack;

Stack Stack_Create(void);
void Stack_MakeEmpty(Stack s);
void Stack_DisposeStack(Stack s);

int Stack_IsEmpty(Stack s);

int Stack_Push(ElementType x, Stack s);
void Stack_Pop(Stack s);
int Stack_FindMin(Stack s);

#endif // _Stack_h
