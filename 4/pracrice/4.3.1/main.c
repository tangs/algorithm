#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main() {
    SearchTree t = Tree_Insert(3, NULL);
    // Tree_Insert(2, t);
    // Tree_Insert(8, t);
    // Tree_Insert(4, t);
    // Tree_Insert(20, t);
    // Tree_Insert(1, t);
    // Tree_Insert(20, t);
    // Tree_Insert(1, t);
    for (int i = 0; i < 100; ++i) {
        int num = rand() % 100;
        Tree_Insert(num, t);
    }
    Tree_Prints(t);
    return 0;
}
