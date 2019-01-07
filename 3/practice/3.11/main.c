#include <stdio.h>
// #include <time.h>
#include <sys/timeb.h>

#include "List.h"

int64_t getSystemTime() {
	struct timeb t;
	ftime(&t);
	return (int64_t)t.time * 1000 + t.millitm;
}

int main() {
    List l = CreateList();
    for (int i = 0; i < 100000; ++i) {
        Insert(i, l, l);
    }
    Position first = First(l);

    int64_t time1, time2, time3;
    time1 = getSystemTime();
    Position p1 = FindRec(0, first, l);
    time2 = getSystemTime();
    Position p2 = FindNRec(0, first, l);
    time3 = getSystemTime();

    printf("find %d with recursion use time %lld.\n", Retrieve(p1, l), (time2 - time1));
    printf("find %d with not recursion use time %lld.\n", Retrieve(p2, l), (time3 - time2));

    DisposeList(l);
    return 0;
}
