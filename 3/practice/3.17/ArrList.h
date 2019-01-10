#ifndef _ArrList_h
#define _ArrList_h

#define POS_END -1

struct Node;

typedef struct Node* PtrToNode;
typedef int Position;
typedef PtrToNode List;

typedef int ElementType;

List CreateList(int capacity);
void MakeEmpty(List l);
void DisposeList(List l);

int First(List l);

void Insert(ElementType x, Position p, List l);
int Delete(Position p, List l);

ElementType Retrieve(Position p, List l);
Position Advance(Position p, List l);

#endif // _ArrList_h
