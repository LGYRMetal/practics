/* 3.4 给定两个已排序的表L1和L2,只使用基本的表操作编写计算L1交L2的过程。 */
#include "list.h"

List intersection(List L1, List L2)
{
    Position P1, P2, P3;
    List L3 = CreateList();

    if(IsEmpty(L1) || IsEmpty(L2)) {
        return L3;
    }

    P1 = L1->Next;
    P2 = L2->Next;
    while(P1 && P2) {
        if(P1->Element == P2->Element) {
        }
    }

    return L3;
}
