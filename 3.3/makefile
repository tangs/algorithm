objects = StackArr.o

debug : main.o Stack.o
	cc -g -o main main.o Stack.o

bs : BalanceSymbol.o StackArr.o
	cc -g -o main BalanceSymbol.o StackArr.o

main.o : StackArr.h
BalanceSymbol.o : StackArr.h Def.h
StackArr.o : StackArr.h Def.h

.PHONY : clean
clean : 
	rm bs main main.o BalanceSymbol.o StackArr.o Stack.o
