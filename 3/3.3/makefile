objects = StackArr.o

debug : main.o Stack.o
	cc -g -o main main.o Stack.o

bs : BalanceSymbol.o StackArr.o
	cc -g -o main BalanceSymbol.o StackArr.o

calc : Calc.o Calculator.o StackArr.o
	cc -g -o main Calc.o Calculator.o StackArr.o

main.o : StackArr.o
BalanceSymbol.o : StackArr.o
Calc.o : Calculator.o

Calculator.o : StackArr.o
StackArr.o : StackArr.h Def.h

.PHONY : clean
clean : 
	rm bs main main.o BalanceSymbol.o StackArr.o Stack.o
