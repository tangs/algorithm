#ifndef _Cursor_H
#define _Cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

void InitializeCursorSpace(void);

List CreatList();
List MakeEmpty(List l);
int isEmpty(const List l);
int isLast(const Position p, const List l);
Position Find(ElementType x, const List l);
Position GetLast(List l);
Position FindPrevious(ElementType x, const List l);
void Delete(ElementType x, List l);
void Insert(ElementType x, List l, Position p);
void Append(ElementType x, List l);
void DeleteList(List l);
Position Header(const List l);
Position First(const List l);
Position Advance(const Position p);
ElementType Retrieve(const Position p);
void PrintElements(List l);

#endif // _Cursor_H
