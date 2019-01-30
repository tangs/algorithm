#include "Tree.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Tree_Node {
    ElementType element;
    SearchTree left;
    SearchTree right;
    int height;
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

int Tree_GetHeight(SearchTree t) {
    if (t == NULL)
        return -1;
    return t->height;
}

int Tree_UpdteHeight(SearchTree t) {
    if (t == NULL) {
        return -1;
    }
    int lDp = Tree_GetHeight(t->left);
    int rDp = Tree_GetHeight(t->right);
    t->height = (lDp > rDp ? lDp : rDp) + 1;
    return t->height;
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
        tree->height = 0;
        return tree;
    }
    if (x == t->element)
        return t;
    if (x < t->element) {
        t->left = Tree_Insert(x, t->left);
    } else if (x > t->element) {
        t->right = Tree_Insert(x, t->right);
    }
    SearchTree left = t->left;
    SearchTree right = t->right;
    Tree_UpdteHeight(t);
    int lDp = Tree_GetHeight(left);
    int rDp = Tree_GetHeight(right);
    if (abs(lDp - rDp) > 1) {
        if (lDp > rDp) {
            if (Tree_GetHeight(left->left) > Tree_GetHeight(left->right)) {
                // case 1
                t->left = left->right;
                left->right = t;
                Tree_UpdteHeight(t);
                Tree_UpdteHeight(left);
                return left;
            } else {
                // case 2
                SearchTree tmp = left->right;
                left->right = tmp->left;
                t->left = tmp->right;
                tmp->left = left;
                tmp->right = t;
                Tree_UpdteHeight(left);
                Tree_UpdteHeight(t);
                Tree_UpdteHeight(tmp);
                return tmp;
            }
        } else {
            if (Tree_GetHeight(right->left) > Tree_GetHeight(right->right)) {
                // case 3
                SearchTree tmp = right->left;
                right->left = tmp->right;
                t->right = tmp->left;
                tmp->right = right;
                tmp->left = t;
                Tree_UpdteHeight(right);
                Tree_UpdteHeight(t);
                Tree_UpdteHeight(tmp);
                return tmp;
            } else {
                // case 4
                t->right = right->left;
                right->left = t;
                Tree_UpdteHeight(t);
                Tree_UpdteHeight(right);
                return right;
            }
        }
    }
    return t;
}

SearchTree Tree_Delete(ElementType x, SearchTree t) {
    if (t == NULL)
        return NULL;
    if (x < t->element)
        t->left = Tree_Delete(x, t->left);
    else if (x > t->element)
        t->right = Tree_Delete(x, t->right);
    else if (t->left && t->right) {
        SearchTree tmp = Tree_FindMin(t->right);
        t->element = tmp->element;
        t->right = Tree_Delete(tmp->element, t->right);
    } else {
        SearchTree tmp = t->left ? t->left : t->right;
        free(t);
        return tmp;
    }
    return t;
}

ElementType Tree_Retrieve(Tree_Pos p) {
    if (p == NULL)
        return 0;
    return p->element;
}

void Tree_Prints(SearchTree t, int dp) {
    if (t == NULL)
        return;
    Tree_Prints(t->left, dp + 1);
    for (int i = 0; i < dp; ++i)
        printf("\t");
    printf("%d\n", t->element);
    Tree_Prints(t->right, dp + 1);
}
