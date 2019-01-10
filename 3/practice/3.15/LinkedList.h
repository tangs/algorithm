#ifndef _LinkedList_h
#define _LinkedList_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef int ElementType;

List CreateList(void);
void MakeEmpty(List l);
void DisposeList(List l);

Position Header(List l);
Position First(List l);

void Add(ElementType x, List l);
Position Find(ElementType x, List l);

ElementType Retrieve(Position p);
int GetFindCount(Position p);
Position Advance(Position p, List l);

#endif // _LinkedList_h
