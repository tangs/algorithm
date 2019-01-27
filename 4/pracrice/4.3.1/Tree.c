#include "Tree.h"

#include <stdlib.h>
#include <stdio.h>

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

SearchTree Tree_Insert(ElementType x, SearchTree t) {
    if (t == NULL) {
        SearchTree tree = malloc(sizeof(struct Tree_Node));
        if (tree == NULL)
            // out of memory.
            return NULL;
        tree->left = NULL;
        tree->right = NULL;
        tree->element = x;
        return tree;
    }
    if (x == t->element)
        return t;
    if (x < t->element)
        t->left = Tree_Insert(x, t->left);
    else if (x > t->element)
        t->right = Tree_Insert(x, t->right);
    return t;
}

SearchTree Tree_Delete(ElementType x, SearchTree t);

ElementType Tree_Retrieve(Tree_Pos p) {
    if (p == NULL)
        return 0;
    return p->element;
}

void Tree_Prints(SearchTree t) {
    if (t == NULL)
        return;
    Tree_Prints(t->left);
    printf("%d\n", t->element);
    Tree_Prints(t->right);
}
