#include <stdio.h>

#include "Polynomial.h"


void PrintPolynomial(Polynomial p) {
    Position pos = First(p);
    int isFirst = 1;
    while (pos != NULL) {
        if (!isFirst) printf("+");
        printf("%dX^%d", Coefficient(pos), Exponent(pos));
        pos = Advance(pos);
        isFirst = 0;
    }
    printf("\n");
}

void AdditionPolynomialToDest(Polynomial p, Polynomial dest) {
    Position pos = First(p);
    while (pos != NULL) {
        int coe = Coefficient(pos);
        int exp = Exponent(pos);
        Add(coe, exp, dest);
        pos = Advance(pos);
    }
}

// 3.6
Polynomial AdditionPolynomial(Polynomial p1, Polynomial p2) {
    Polynomial sum = CreatePolynomial();
    AdditionPolynomialToDest(p1, sum);
    AdditionPolynomialToDest(p2, sum);
    return sum;
}

Polynomial MultiplyPolynomial(Polynomial p1, Polynomial p2) {
    Polynomial ret = CreatePolynomial();
    Position pos1 = First(p1);
    while (pos1 != NULL) {
        int coe1 = Coefficient(pos1);
        int exp1 = Exponent(pos1);
        Position pos2 = First(p2);
        while (pos2 != NULL) {
            int coe2 = Coefficient(pos2);
            int exp2 = Exponent(pos2);
            Add(coe1 * coe2, exp1 + exp2, ret);
            pos2 = Advance(pos2);
        }
        pos1 = Advance(pos1);
    }
    return ret;
}

int main() {
    Polynomial p1 = CreatePolynomial();
    Polynomial p2 = CreatePolynomial();

    // 1+2x
    Add(1, 0, p1);
    Add(2, 1, p1);

    // 1+2x+x^2
    Add(1, 0, p2);
    Add(2, 1, p2);
    Add(1, 2, p2);

    Polynomial sum = AdditionPolynomial(p1, p2);
    Polynomial multiply = MultiplyPolynomial(p1, p2);

    PrintPolynomial(p1);
    PrintPolynomial(p2);
    PrintPolynomial(sum);
    PrintPolynomial(multiply);

    DisposePolynomial(p1);
    DisposePolynomial(p2);
    DisposePolynomial(sum);
    DisposePolynomial(multiply);
}
