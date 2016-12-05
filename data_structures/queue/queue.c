#include "queue.h"

/* Queue implementation is a dynamically allocated array */
#deinfe MinQueueSize    (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

/* 我的实现
void MakeEmpty(Queue Q)
{
    while(Q->Size > 0) {
        Dequeue(Q);
    }
} */

/* 书上的实现 */
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q)) {
        Error("Queue is full");
    }

    Q->Array[Succ(Q->Rear, Q)] = X;
    Q->Size++;
}
