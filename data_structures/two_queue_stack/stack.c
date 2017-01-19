/* 思路: 两个队列Q1, Q2; Q1作为栈, Q2做缓冲 */
/* O(1) */
STACK-EMPTY(S)
    if Q1.head == Q1.tail
        return TRUE
    return FALSE

/* O(1) */
PUSH(S, x)
    if Q1.head == Q1.tail + 1
        error "overflow"
    else ENQUEUE(Q1, x)
        if Q1.tail == 1
            S.top = Q1.length
        else S.top = Q1.tail - 1

/* O(N) */
POP(S)
    if STACK-EMPTY(S)
        error "underflow"
    else
        if Q1.tail == 1
            while Q1.head < Q1.length
                ENQUEUE(Q2, DEQUEUE(Q1))
        else
            while Q1.head > Q1.tail-1
                ENQUEUE(Q2, DEQUEUE(Q1))

        x = DEQUEUE(Q1)
        
        while Q2.head != Q2.tail
            ENQUEUE(Q1, DEQUEUE(Q2))

        S.top = Q1.tail == 1 ? Q1.length : Q1.tail--

        return x
