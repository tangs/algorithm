#include "Queue.h"

#include <stdio.h>

int main() {
    Queue q = Queue_Create();
    for (int i = 0; i < 100; ++i) {
        Queue_Enqueue(i, q);
    }
    while (!Queue_IsEmpty(q)) {
        printf("%d ", Queue_FrontAndDequeue(q));
    }
    printf("\n");
    Queue_Dispose(q);
    return 0;
}
