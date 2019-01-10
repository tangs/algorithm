#ifndef _ArrList_h
#define _ArrList_h

struct Node;
typedef struct Node *PtrToNode;
typedef int Position;
typedef PtrToNode List;

typedef int ElementType;

List CreateList(int capacity);
void MakeEmpty(List l);
void DisposeList(List l);

Position Header(List l);
Position First(List l);

void QuickSort(List l);

void Insert(ElementType x, Position p, List l);
void Delete(Position p, List l);
void DeleteRepeat(List l);

ElementType Retrieve(Position p, List l);
Position Advance(Position p, List l);

#endif // _ArrList_h
