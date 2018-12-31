#ifndef _Polynomial_h
#define _Polynomial_h

struct Node;

typedef struct Node *PrtToNode;
typedef PrtToNode Position;
typedef PrtToNode Polynomial;

Polynomial CreatePolynomial(void);
void DisposePolynomial(Polynomial p);
Position Header(Polynomial p);
Position First(Polynomial p);
void Set(int coefficient, int exponent, Polynomial p);
void Add(int coefficient, int exponent, Polynomial p);
int Coefficient(Position p);
int Exponent(Position p);
Position Advance(Position p);

#endif // _Polynomial_h
