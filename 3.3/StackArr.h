#ifndef _Stack_h
#define _Stack_h

struct StackRecord;
typedef struct StackRecord *Stack;

typedef int ElementType;

Stack CreateStack(int maxElements);
int IsEmpty(Stack s);
int IsFull(Stack s);
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(ElementType x, Stack s);
ElementType Top(Stack s);
void Pop(Stack s);

#endif // _Stack_h
