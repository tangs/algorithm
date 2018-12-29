#ifndef _Queue_h
#define _Queue_h

#include "def.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue CreateQueue(int maxElements);
void DisposeQueue(Queue q);
int IsEmpty(Queue q);
int IsFull(Queue q);
void MakeEmpty(Queue q);
void Enqueue(ElementType x, Queue q);
void Dequeue(Queue q);
ElementType Front(Queue q);
ElementType FrontAndDequeue(Queue q);

#endif// _Queue_h
