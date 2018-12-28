objects = StackArr.o

debug : main.o Stack.o
	cc -g -o main main.o Stack.o

bs : BalanceSymbol.o StackArr.o
	cc -g -o main BalanceSymbol.o StackArr.o

calc : Calc.o Calculator.o StackArr.o
	cc -g -o main Calc.o Calculator.o

main.o : StackArr.h
BalanceSymbol.o : StackArr.h Def.h
Calc.o : Calculator.h
Calculator.o : StackArr.h
StackArr.o : StackArr.h Def.h

.PHONY : clean
clean : 
	rm bs main main.o BalanceSymbol.o StackArr.o Stack.o
