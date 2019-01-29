#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main() {
    SearchTree t = Tree_Insert(3, NULL);
    t = Tree_Insert(2, t);
    t = Tree_Insert(8, t);
    t = Tree_Insert(4, t);
    t = Tree_Insert(20, t);
    t = Tree_Insert(1, t);
    t = Tree_Insert(40, t);
    t = Tree_Insert(15, t);
    t = Tree_Insert(16, t);
    t = Tree_Insert(17, t);
    t = Tree_Insert(30, t);
    t = Tree_Insert(15, t);
    t = Tree_Insert(5, t);
    // for (int i = 0; i < 100; ++i) {
    //     int num = rand() % 100;
    //     Tree_Insert(num, t);
    // }
    Tree_Prints(t, 0);
    // printf("\n\n\n");
    // t = Tree_Delete(8, t);
    // Tree_Prints(t, 0);
    // printf("\n\n\n");
    return 0;
}
