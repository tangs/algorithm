#ifndef _LinkedList_h
#define _LinkedList_h

#include "Def.h"

struct ListNode; 

typedef struct ListNode *PtrToListNode;
typedef PtrToListNode ListPos;
typedef PtrToListNode List;

List List_Create();
void List_MakeEmpty(List l);
void List_DisposeList(List l);

ListPos List_Header(List l);
ListPos List_First(List l);

int List_IsEmpty(List l);
int List_IsHeader(ListPos p, List l);

void List_Append(ElementType element, List l);
void List_AddToHead(ElementType element, List l);

ElementType List_Retrieve(ListPos p, List l);
ListPos List_Advance(ListPos p, List l);

#endif // _LinkedList_h
