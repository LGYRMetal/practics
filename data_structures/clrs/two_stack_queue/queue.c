/** 
 * 思路：两个栈S1,S2,用S1作为队列, 用S2作为缓冲区, Q.head 恒等于 S1[1], 
 * Q.tail 恒等于S1[S1.top+1], Q.length = S1.length
 */
/* O(1) */
ENQUEUE(Q, x)
    if Q.tail == Q.length
        error "overflow"
    else PUSH(S1, x)
        Q.tail++

/* O(N) */
DEQUEUE(Q)
    if STACK-EMPTY(S1)
        error "underflow"
    else
        while (S1.top > 1)
            PUSH(S2, POP(S1))

        x = POP(S1)
        
        while (!STACK-EMPTY(S2))
            PUSH(S1, POP(S2))

        Q.tail--
        return x
