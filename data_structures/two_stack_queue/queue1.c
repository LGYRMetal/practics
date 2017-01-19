/**
 * 思路2: 两个栈S1, S2不固定那个是缓冲，但Q.length只能是一个栈的长度,
 * 一个栈作为队列的时候另一个就是缓冲，反之亦然,DEQUEUE比思路一要省时,
 * ENQUEUE比思路一要费时
 * 队列是空时，即两个栈也是空，那么S1作为栈，S2 作为缓冲, S1和S2同时非空的情
 * 况不能出现
 */
/* O(N) */
ENQUEUE(Q, x)
    if !STACK-EMPTY(S1) /* 非空队列, 并且队列元素在S1中 */
        if S1.top == S1.length
            error "overflow"
        else
            if Q.head == 1  /* 栈底是队首 */
                PUSH(S1, x)
                Q.tail++
            else /* 栈顶是队首 */
                while !STACK-EMPTY(S1) /* 倒栈 */
                    PUSH(S2, POP(S1))
                PUSH(S2, x)
                Q.head = 1
                Q.tail = S2.top + 1

    else if !STACK-EMPTY(S2) /* 非空队列， 队列元素在S2中 */
        if S2.top == S2.length
            error "overflow"
        else
            if Q.head == 1 /* 栈底是队首 */
                PUSH(S2, x)
                Q.tail++
            else /* 栈顶是队首 */
                while !STACK-EMPTY(S2) /* 倒栈 */
                    PUSH(S1, POP(S2))
                PUSH(S1, x)
                Q.head = 1
                Q.tail = S1.top + 1

    else /* S1, S2都是空栈，空队列 */
        PUSH(S1, x)
        Q.head = 1
        Q.tail = S1.top + 1

/* O(N) */
DEQUEUE(Q)
    if !STACK-EMPTY(S1) /* 队列元素在S1中 */
        if Q.head == 1  /* 栈底是队首 */
            while S1.top > 1 /* 倒栈 */
                PUSH(S2, POP(S1))
            x = POP(S1)
            Q.head = S2.top
            Q.tail = 0
        else /* 栈顶是队首 */
            x = POP(S1)
            Q.head--

    else if !STACK-EMPTY(S2) /* 队列元素在S2中 */
        if Q.head == 1 /* 栈底是队首 */
            while S2.top > 1 /* 倒栈 */
                PUSH(S1, POP(S2))
            x = POP(S2)
            Q.head = S1.top
            Q.tail = 0
        else /* 栈顶是队首 */
            x = POP(S2)
            Q.head--

    else /* 空队列 */
        error "underflow"
