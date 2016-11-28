#include "list.h"

struct Node {
    ElementType Element;
    Position    Next;
};

/* 我的实现, 不够简练 */
/*
int IsEmpty(List L)
{
    if(L->Next == NULL)
        return True;

    return False;
}
*/

/* 书上的实现方法, 非常简练 */
int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    if(!IsEmpty(L)) {
        return P->Next == NULL;
    }
}

/* 我的实现，有错误，忘了头节点的存在，而且改变了L的值，这样不好, 而且不够简练
Position Find(ElementType X, List L)
{
    while(!IsEmpty(L) && (L->Next != NULL)) {
        if(X == L->Element) {
            return L;
        }

        L = L->Next;
    }
}
*/

/* 书中的实现 */
Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while(P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}

void Delete(ElementType X, List L)
{
    Position P1;
    Position P2;

    P1 = L->Next;
    while(P1 != NULL && P1->Element != X) {
        P2 = P1;
    }

    if(P != NULL) {

    }
}
