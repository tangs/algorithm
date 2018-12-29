#include <stdio.h>

#include "Queue.h"

int main() {
    Queue q = CreateQueue(5);
    Enqueue(1, q);
    Enqueue(2, q);
    Enqueue(3, q);
    Enqueue(4, q);
    Dequeue(q);
    Dequeue(q);
    Enqueue(5, q);
    Enqueue(6, q);
    Enqueue(7, q);
    while(!IsEmpty(q))
        printf("%d\n", FrontAndDequeue(q));
    // Dequeue(q);
    DisposeQueue(q);
}
