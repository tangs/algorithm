#ifndef _Deque_h
#define _Deque_h

#include "Def.h"

struct Deque_Node;
typedef struct Deque_Node *PtrToDeque_Node;
typedef PtrToDeque_Node Deque_Pos;
typedef PtrToDeque_Node Deque;

Deque Deque_Create(void);
void Deque_Dispose(Deque d);

void Deque_MakeEmpty(Deque d);

int Deque_IsEmpty(Deque d);

void Deque_Push(ElementType x, Deque d);
ElementType Deque_Pop(Deque d);
void Deque_Inject(ElementType x, Deque d);
ElementType Deque_Eject(Deque d);

#endif // _Deque_h
