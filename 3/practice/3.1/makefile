objects = main.o List.o
sources = main.c List.c

main : $(objects)
	cc -o main $(objects)

main.o : List.o

List.o : List.h def.h

.PHONY : clean debug

debug : $(sources)
	cc -g -o main $(sources)

main.c : List.c

List.c : List.h def.h

clean : 
	rm -rf main.dSYM main $(objects)
	