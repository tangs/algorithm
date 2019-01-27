#include "Tree.h"

#include <stdlib.h>

struct Tree_Node {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree Tree_MakeEmpty(SearchTree t) {
    if (t != NULL) {
        Tree_MakeEmpty(t->left);
        Tree_MakeEmpty(t->right);
        free(t);
    }
    return NULL;
}

Tree_Pos Tree_Find(ElementType x, SearchTree t) {
    if (t == NULL)
        return NULL;
    if (x > t->element)
        return Tree_Find(x, t->right);
    if (x < t->element)
        return Tree_Find(x, t->left);
    return t;
}

Tree_Pos Tree_FindMin(SearchTree t) {
    if (t == NULL) 
        return NULL;
    if (t->left)
        return Tree_FindMin(t->left);
    return t;
}

Tree_Pos Tree_FindMax(SearchTree t) {
    if (t == NULL)
        return NULL;
    if (t->right) {
        return Tree_FindMin(t->right);
    return t;
}

SearchTree Insert(ElementType x, SearchTree t);
SearchTree Delete(ElementType x, SearchTree t);
ElementType Retrieve(Tree_Pos p);
