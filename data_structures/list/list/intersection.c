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
    P3 = L3;
    while(P1 && P2) {
        if(P1->Element == P2->Element) {
            Insert(P1->Element, L3, P3);
            P3 = P3->Next; /* 保证每次都插入到表尾 */
            P1 = P1->Next;
            P2 = P2->Next;
        }
        else if(P1->Element < P2->Element) {
            /* 两个表都是已排序的表,所以如果P1元素小于P2元素, 那么P1的下一个
             * 元素有可能与P2的相等,反之亦然 */
            P1 = P1->Next;
        }
        else if(P1->Element > P2->Element) {
            P2 = P2->Next;
        }
    }

    return DeDuplication(L3);
}
