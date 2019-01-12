#include <stdio.h>
#include <stdlib.h>

long fab(long num) {
    if (num == 1 || num == 2)
        return 1;
    return fab(num - 1) + fab(num - 2);
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        long num = atoi(argv[i]);
        printf("fab(%ld)=%ld\n", num, fab(num));
    }
    return 0;    
}