objects = main.o StackArr.o

debug : $(objects)
	cc -g -o main $(objects)

main.o : StackArr.h
StackArr.o : StackArr.h

.PHONY : clean
clean : 
	rm main $(objects)
