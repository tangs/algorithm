#ifndef _CricLinkedList_h
#define _CricLinkedList_h

struct Node;
typedef struct Node *PrtToNode;
typedef PrtToNode Position;
typedef PrtToNode List;

typedef int ElementType;

List CreateList(void);
void MakeEmpty(List l);
void DisposeList(List l);
int IsEmpty(List l);
int IsFirst(Position p, List l);
int IsLast(Position p, List l);
Position Header(List l);
Position First(List l);
Position Last(List l);
Position Next(Position p, List l);
Position Prev(Position p, List l);
void Insert(ElementType x, Position p, List l);
void Append(ElementType x, List l);
Position Delete(Position p, List l);
ElementType Retrieve(Position p, List l);
Position Advance(Position p, List l);

#endif // _CricLinkedList_h
