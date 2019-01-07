#ifndef _Number_h
#define _Number_h

#define NUMBER_OVERFLOWBITS 10
#define NUMBER_OVERFLOWVALUE 1000000000

struct Node;

typedef struct Node *PrtToNode;
typedef PrtToNode Position;
typedef PrtToNode Number;

Number CreateNumber(void);
void DisposeNumber(Number num);
Position Header(Number num);
Position First (Number num);
void SetValue(int digit, int value, Number num);
void AddValue(int digit, int value, Number num);
int Digit(Number num);
int Value(Number num);
Position GetPostion(int digit, Number num);
Number Add(Number num1, Number num2);
Number Sub(Number num1, Number num2);
Number Mut(Number num1, Number num2);
Number Div(Number num1, Number num2);
Position Advance(Number num);

#endif // _Number_h
