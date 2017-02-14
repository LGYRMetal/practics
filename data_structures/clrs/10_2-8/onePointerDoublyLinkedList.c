#include <stdio.h>
#include "onePointerDoublyLinkedList.h"

LIST-SEARCH(L, k)
    L.head = L
    x = L.head
    xPrev = NIL
    xNext = x.np xor xPrev
    while x != NIL and x.key != k
        xPrev = x
        x = xNext
        xNext = x.np xor xPrev
    return x

LIST-INSERT(L, x)
    L.head = L
    xPrev = NIL
    xNext = L.head
    x.np = xPrev xor xNext
    if L.head != NIL
        L.head.np = (L.head.np xor NIL) xor x
        L.head = x
        
LIST-DELETE(L, x)
