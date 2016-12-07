/* 3.3 通过只调整指针(而不是数据)来交换两个相邻的元素，使用
 * a. 单链表
 */

#include "list.h"

static Position find_previous(Position P, List L)
{
    Position Pre;

    if(IsEmpty(L)) {
        Error("Empyt list");
    }

    Pre = L;
    while(!IsLast(Pre, L) && Pre->Next != P) {
        Pre = Pre->Next;
    }

    if(IsLast(Pre, L)) {
        return NULL;
    }

    return Pre;
}

/* 假设交换给定位置和其后面的元素的位置 */
void exchange(List L, Position P)
{
    Position PreNode, NextNode;

    if(IsEmpty(L)) {
        Error("Empty list");
    }

    PreNode = find_previous(P, L);
    NextNode = P->Next;

    PreNode->Next = NextNode;
    P->Next = NextNode->Next;
    NextNode->Next = P;
}
