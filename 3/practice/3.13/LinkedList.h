#ifndef _LinkedList_h
#define _LinkedList_h

#include "Def.h"

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List CreateList(void);
void MakeEmpty(List l);
void DisposeList(List l);

Position Header(List l);
Position First(List l);
Position Last(List l);

int IsHeader(Position p, List l);
int IsFirst(Position p, List l);
int IsLast(Position p, List l);

void Insert(ElementType x, Position p, List l);
void Append(ElementType x, List l);

Position Delete(Position p, List l);

ElementType Retrieve(Position p);
Position Advance(Position p, List l);

#endif // _LinkedList_h
