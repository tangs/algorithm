objects = main.o List.o
sources = main.c List.c

list : $(objects)
	cc -o main $(objects)

duList : main.o DuLinkList.o
	cc -o main main.o DuLinkList.o

main.o : List.o

DuLinkList.o : DuLinkList.h def.h

List.o : List.h def.h

.PHONY : clean debug

debug : $(sources)
	cc -g -o main $(sources)

main.c : List.c

List.c : List.h def.h

clean : 
	rm -rf main.dSYM main $(objects)
	