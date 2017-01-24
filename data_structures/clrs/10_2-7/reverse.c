/* 10.2-7 */
REVERSE(L)
    x = L.head.next
    tmp = x.next
    x.next = NULL
    L1.head.next = x
    x = tmp
    while x != NULL
        tmp = x.next
        x.next = L1.head.next
        L1.head.next = x
        x = tmp
