/* 用一个单链表L实现一个栈。要求操作PUSH和POP的运行时间仍为O(1) */
/* 设x是指向入栈和出栈的元素的指针 */
PUSH(S, x)
    x.next = L.head.next
    L.head.next = x

POP(S)
    if L.head.next == NULL /* 空栈 */
        error "underflow"
    else
        x = L.head.next
        L.head.next = x.next

    return x
