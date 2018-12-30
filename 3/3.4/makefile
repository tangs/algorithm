objects = main.o Queue.o

main : $(objects)
	cc -g -o main $(objects)

main.o : Queue.o
Queue.o : Queue.h Def.h

.PHONY : clean
clean :
	rm main $(objects)
