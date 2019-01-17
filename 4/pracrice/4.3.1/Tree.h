#ifndef _Tree_h
#define _Tree_h

struct Tree_Node;
typedef struct Tree_Node *Tree_Pos;
typedef struct Tree_Node *SearchTree;

SearchTree Tree_MakeEmpty(SearchTree t);
Position Tree_Find(ElementType x, SearchTree t);

#endif // _Tree_h
