#include <stdio.h>

#include "Calculator.h"

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        printf("%d\n", calc(argv[i]));
    }
}
