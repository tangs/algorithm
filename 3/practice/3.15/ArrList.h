#ifndef _ArrList_h
#define _ArrList_h

struct Node;
typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef int ElementType;

// List CreateList(int capacity);
void InitializeCursorSpace(void);

List CreateList(void);
void MakeEmpty(List l);

int IsFirst(Position p, List l);
int IsLast(Position p, List l);

void Add(ElementType x, List l);

Position First(List l);
Position Find(ElementType x, List l);

ElementType Retrieve(Position p);
Position Advance(Position p, List l);

#endif // _ArrList_h
