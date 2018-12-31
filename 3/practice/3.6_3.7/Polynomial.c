#include "Polynomial.h"

#include <stdlib.h>
#include <memory.h>

struct Node {
    int coefficient;
    int exponent;
    PrtToNode next;
};

Polynomial CreatePolynomial(void) {
    Polynomial p = malloc(sizeof(struct Node));
    if (p == NULL) {
        // out of memory.
        return NULL;
    }
    memset(p, 0, sizeof(struct Node));
    return p;
}

void DisposePolynomial(Polynomial p) {
    Polynomial tmp;
    while (p != NULL) {
        tmp = p;
        p = p->next;
        free(tmp);
    }
}

Position Header(Polynomial p) {
    return p;
}

Position First(Polynomial p) {
    return p->next;
}

void Set(int coefficient, int exponent, Polynomial p) {
    Polynomial prev = p;
    p = p->next;
    while (p && p->exponent < exponent) {
        prev = p;
        p = p->next;
    }
    if (p && p->exponent == exponent) {
        p->coefficient = coefficient;
    } else {
        Position node = malloc(sizeof(struct Node));
        node->coefficient = coefficient;
        node->exponent = exponent;
        node->next = prev->next;
        prev->next = node;
    }
}

void Add(int coefficient, int exponent, Polynomial p) {
    Polynomial prev = p;
    p = p->next;
    while (p && p->exponent < exponent) {
        prev = p;
        p = p->next;
    }
    if (p && p->exponent == exponent) {
        p->coefficient += coefficient;
    } else {
        Position node = malloc(sizeof(struct Node));
        node->coefficient = coefficient;
        node->exponent = exponent;
        node->next = prev->next;
        prev->next = node;
    }
}

int Coefficient(Position p) {
    return p->coefficient;
}

int Exponent(Position p) {
    return p->exponent;
}

Position Advance(Position p) {
    return p->next;
}
