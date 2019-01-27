#ifndef _Tree_h
#define _Tree_h

#include "Def.h"

struct Tree_Node;
typedef struct Tree_Node *Tree_Pos;
typedef struct Tree_Node *SearchTree;

SearchTree Tree_MakeEmpty(SearchTree t);
Tree_Pos Tree_Find(ElementType x, SearchTree t);
Tree_Pos Tree_FindMin(SearchTree t);
Tree_Pos Tree_FindMax(SearchTree t);
SearchTree Tree_Insert(ElementType x, SearchTree t);
SearchTree Tree_Delete(ElementType x, SearchTree t);
ElementType Tree_Retrieve(Tree_Pos p);
void Tree_Prints(SearchTree t);

#endif // _Tree_h
