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
    if (t->left != NULL)
        return Tree_FindMin(t->left);
    return t;
}

Tree_Pos Tree_FindMax(SearchTree t) {
    if (t != NULL)
        while (t->right != NULL)
            t = t->right;
    return t;
}

SearchTree Insert(ElementType x, SearchTree t) {
    if (t == NULL)
        return NULL;
    if (x == t->element)
        return t;
    if (x < t->element)
        if (t->left != NULL)
            return Insert(x, t->left);
        else {
            SearchTree tree = malloc(sizeof(struct Tree_Node));
            tree->left = NULL;
            tree->right = NULL;
            tree->element = x;
            t->left = tree;
            return tree;
        }
    if (x > t->element)
        if (t->right != NULL)
            return Insert(x, t->right);
        else {
            SearchTree tree = malloc(sizeof(struct Tree_Node));
            tree->right = NULL;
            tree->right = NULL;
            tree->element = x;
            t->right = tree;
            return tree;
        }
    return t;
}

SearchTree Delete(ElementType x, SearchTree t);
ElementType Retrieve(Tree_Pos p);
