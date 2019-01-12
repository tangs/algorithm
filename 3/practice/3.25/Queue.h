#ifndef _Queue_h
#define _Queue_h

#include "Def.h"

struct Queue_Node;

typedef struct Queue_Node *Queue_Pos;
typedef Queue_Pos Queue;

Queue Queue_Create();
void Queue_Dispose(Queue q);

void Queue_MakeEmpty(Queue q);

int Queue_IsEmpty(Queue q);

void Queue_Enqueue(ElementType x, Queue q);
ElementType Queue_Front(Queue q);
void Queue_Dequeue(Queue q);
ElementType Queue_FrontAndDequeue(Queue q);

#endif // _Queue_h
