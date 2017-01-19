/* 思路2：类似two_stack_queue思路2,两个队列不可能同时非空 */
/* O(1) */
STACK-EMPTY(S)
    if (Q1.head == Q1.tail) && (Q2.head == Q2.tail)
        return TRUE
    return FALSE

/* O() */
PUSH(S, x)
    if Q1.head != Q1.tail /* 栈元素在Q1中 */
        if (Q1.head == 1 && Q1.tail == Q1.length) || (Q1.head == Q1.tail+1)
            error "overflow"
        else if (S.top == Q1.head) && /* 栈顶在队首 */
                (Q1.head != Q1.tail-1) && /* 而且是队中元素数大于1 */
                !(Q1.head == Q1.lenth && Q1.tail == 1)
            ENQUEUE(Q2, x)
            while Q1.head != Q1.tail /* 倒队列 */
                ENQUEUE(Q2, DEQUEUE(Q1))
            S.top = Q2.head
        else /* 栈顶在队尾, 或者在队首但是只有一个元素 */
            ENQUEUE(Q1, x)
            S.top++

    else if Q2.head != Q2.tail /* 栈元素在Q2中 */
        if (Q2.head == 1 && Q2.tail == Q2.length) || (Q2.head == Q2.tail+1)
            error "overflow"
        else if (S.top == Q2.head) /* 栈顶在队首 */
                (Q2.head != Q2.tail-1) && /* 而且是队中元素数大于1 */
                !(Q2.head == Q2.lenth && Q2.tail == 1)
            ENQUEUE(Q1, x)
            while Q2.head != Q2.tail /* 倒队列 */
                ENQUEUE(Q1, DEQUEUE(Q2))
            S.top = Q1.head
        else /* 栈顶在队尾 */
            ENQUEUE(Q2, x)
            S.top++

    else /* 空栈, 这种情况下Q1默认为栈元素，Q2默认为缓冲区 */
        ENQUEUE(Q1, x)
        S.top = Q1.head
