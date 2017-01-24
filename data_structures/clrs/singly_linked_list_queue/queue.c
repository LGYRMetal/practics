/* 用一个单链表L实现一个队列。要求操作ENQUEUE和DEQUEUE的运行时间仍为O(1) */
/* 假设x为指向入队和出队的元素的指针 */
/* L.head作为Q.head, L.tail作为Q.tail */
/* 初始状态时,空表时, Q.head = Q.tail = Q.L.head */
ENQUEUE(Q, x)
    x.next = Q.tail.next
    Q.tail.next = x
    Q.tail = x

DEQUEUE(Q)
    if Q.head == Q.tail /* 空表 */
        error "underflow"
    else
        x = Q.head.next
        Q.head.next = x.next
    return x
