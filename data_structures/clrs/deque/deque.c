ENQUEUE_FROM_HEAD(Q, x)
    if (Q.head == Q.tail + 1) || (Q.head == 1 && Q.tail == Q.length)
        error "overflow"
    else
        if Q.head == 1
            Q.head = Q.length
        else Q.head--
        Q[Q.head] = x

ENQUEUE_FROM_TAIL(Q, x)
    if (Q.head == Q.tail + 1) || (Q.head == 1 && Q.tail == Q.length)
        error "overflow"
    else
        Q[Q.tail] = x
        if Q.tail == Q.length
            Q.tail = 1
        else Q.tail++

DEQUEUE_FROM_HEAD(Q)
    if Q.head == Q.tail
        error "underflow"
    else
        x = Q[Q.head]
        if Q.head == Q.length
            Q.head = 1
        else Q.head++
        return x

DEQUEUE_FROM_TAIL(Q)
    if Q.head == Q.tail
        error "underflow"
    else
        if Q.tail == 1
            Q.tail = Q.length
        else Q.tail--
        return Q[Q.tail]
