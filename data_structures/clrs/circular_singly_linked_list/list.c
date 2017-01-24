/* 算法导论10.2-5:使用单向循环链表实现字典操作INSERT、DELETE和SEARCH */
/* x是指向已设置好关键字key的元素的指针 */
/* k是关键字key */

/* O(1) */
INSERT(L, x)
    x.next = L.nil.next
    L.nil.next = x

/* O(N) */
DELETE(L, k)
    x = L.nil
    while x.next != L.nil && x.next.key != k
        x = x.next
    if x.next != L.nil
        x.next = x.next.next

/* O(N) */
SEARCH(L, k)
    x = L.nil.next
    while x != L.nil && x.key != k
        x = x.next
    return x
