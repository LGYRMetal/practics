/* 3.5 给定两个已排序的表L1和L2,只使用基本的表操作编写计算L1并L2的过程。 */

#include "list.h"

List Union(List L1, List L2)
{
    Position P1, P2, P3;
    List L3 = CreateList();

    /* 下面两种情况已包含L1和L2都是空表的情况 */
    if(IsEmpty(L1))
        return L2;
    if(IsEmpty(L2))
        return L1;

    P1 = L1->Next;
    P2 = L2->Next;
    P3 = L3;
    while(P1 && P2) {
        if(P1->Element == P2->Element) {
            Insert(P1->Element, L3, P3);
            P1 = P1->Next;
            P2 = P2->Next;
        }
        else if(P1->Element < P2->Element) {
            Insert(P1->Element, L3, P3);
            P1 = P1->Next;
        }
        else if(P1->Element > P2->Element) {
            Insert(P2->Element, L3, P3);
            P2 = P2->Next;
        }
        P3 = P3->Next; /* 每次都插在表尾 */
    }

    if(P1) {
        P3->Next = P1;
    }
    if(P2) {
        P3->Next = P2;
    }

    return L3;
}
