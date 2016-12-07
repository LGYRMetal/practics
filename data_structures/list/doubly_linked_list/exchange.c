/* 3.3 通过只调整指针(而不是数据)来交换两个相邻的元素， 使用
 * b. 双链表
 */
#include "list.h"

/* 假设调换给定位置的元素及其后面相邻元素的位置 */

void exchange(List L, Position P)
{
    Position PreNode  = P->Previous;
    Position NextNode = P->Next;

    if(IsEmpty(L)) {
        Error("Empty list");
    }

    PreNode->Next = NextNode;
    P->Previous = NextNode;
    P->Next = NextNode->Next;
    NextNode->Previous = PreNode;
    NextNode->Next = P;
}
