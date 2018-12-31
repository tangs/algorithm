#ifndef _List_h
#define _List_h

#include "def.h"

struct Node;
typedef struct Node *PrtToNode;
typedef PrtToNode List;
typedef PrtToNode Position;

List CreateList(void);
void DeleteList(List l);
int IsEmpty(List l);
int IsLast(Position p, List l);
Position Find(ElementType x, List l);
Position FindPrevious(ElementType x, List l);
Position GetLast(List l);
void Insert(ElementType x, List l, Position p);
void Append(ElementType x, List l);
void Delete(ElementType x, List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
ElementType Retrieve(Position p);

#endif // _List_h
