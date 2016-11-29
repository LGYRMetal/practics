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

/* 我的例程没有释放被删除的节点的内存
void Delete(ElementType X, List L)
{
    Position P1;
    Position P2;

    P1 = L->Next;
    while(P1 != NULL && P1->Element != X) {
        P2 = P1;
        P1 = P1->Next;
    }

    if(P1 != NULL) {
        P2->Next = P1->Next;
    }
}
*/

/* 书上的例程 */
void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* 我的例程不够简练, 我的例程如果没找到，则返回NULL, 书上的例程如果没找到则返回最后一个节点
Position FindPrevious(ElementType X, List L)
{
    Position P, Pre;

    P = L->Next;
    while(P != NULL && P->Element != X) {
        Pre = P;
        P = P->Next;
    }

    if(P != NULL) {
        return Pre;
    }

    return NULL;
} */

/* 书上的例程非常简练 */
Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while(P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }

    return P;
}

/* 我的例程有错误，node不是指针，不能使用->访问成员
void Insert(ElementType X, List L, Position P)
{
    struct Node node;
    node->Element = X;
    node->Next = P->Next;
    P->Next = &node;
}*/

/* 书上的例程 */
void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/* 我理解的删除表是L只想NULL,而作者的理解是清空表，而且留着头节点
void DeleteList(List L)
{
    Position P, TmpCell;

    P = L;

    while(P != NULL) {
        TmpCell = P;
        P = P->Next;
        free(TmpCell);
    }

    L = NULL;
} */

/* 书上的例程 */
void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next; /* Header assumed */
    L->Next = NULL;
    while(P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
