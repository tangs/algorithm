#ifndef _List_h
#define _List_h

struct Node;

typedef int ElementType;

typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

List CreateList(void);
void DisposeList(List l);

Position Header(List l);
Position First(List l);

void Insert(ElementType x, Position p, List l);

Position FindRec(ElementType x, Position p, List l);
Position FindNRec(ElementType x, Position p, List l);

ElementType Retrieve(Position p, List l);

#endif // _List_h
