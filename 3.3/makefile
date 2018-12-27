objects = main.o Stack.o

debug : $(objects)
	cc -g -o main $(objects)

main.o : Stack.h
Stack.o : Stack.h

.PHONY : clean
clean : 
	rm main $(objects)
