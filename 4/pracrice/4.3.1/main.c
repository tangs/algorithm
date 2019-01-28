#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main() {
    SearchTree t = Tree_Insert(3, NULL);
    Tree_Insert(2, t);
    Tree_Insert(8, t);
    Tree_Insert(4, t);
    Tree_Insert(20, t);
    Tree_Insert(1, t);
    Tree_Insert(20, t);
    Tree_Insert(40, t);
    Tree_Insert(15, t);
    Tree_Insert(16, t);
    Tree_Insert(17, t);
    // for (int i = 0; i < 100; ++i) {
    //     int num = rand() % 100;
    //     Tree_Insert(num, t);
    // }
    Tree_Prints(t);
    printf("\n");
    t = Tree_Delete(8, t);
    Tree_Prints(t);
    printf("\n");
    return 0;
}
