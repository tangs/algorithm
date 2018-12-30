#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

List CreatList();
List MakeEmpty(List l);
int IsEmpty(List l);
int IsLast(Position p, List l);
Position Find(ElementType x, List l);
Position GetLast(List l);
void Delete(ElementType x, List l);
Position FindPrevious(ElementType x, List l);
void Insert(ElementType x, List l, Position p);
void Append(ElementType x, List l);
void DeleteList(List l);
Position Header(List l);
Position First(List l);
Position Advance(Position p);
ElementType Retrieve(Position p);
void PrintElements(List l);

#endif // _List_H
