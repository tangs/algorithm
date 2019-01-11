#ifndef _Stack_h
#define _Stack_h

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode Stack;

typedef int ElementType;

Stack CreateStack(void);
void MakeEmpty(Stack s);
void DisposeStack(Stack s);

int IsEmpty(Stack s);

void Push(ElementType x, Stack s);
void Pop(Stack s);
ElementType Top(Stack s);
ElementType TopAndPop(Stack s);

#endif // _Stack_h
