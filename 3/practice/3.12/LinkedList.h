#ifndef _LinkedList_h
#define _LinkedList_h

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef int ElementType;

List CreateList(void);
void DisposeList(List l);

Position First(List l);

void Insert(ElementType x, Position p, List l);
void Reverse(List l);

ElementType Retrieve(Position p, List l);
Position Advance(Position p, List l);

#endif // _LinkedList_h
