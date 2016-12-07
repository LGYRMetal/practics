#include "list.h"

List CreateList(void)
{
    List L = malloc(sizeof(struct Node));
    if(L == NULL) {
        FatalError("Out of space!!!");
    }

    MakeEmpty(L);

    return L;
}

List MakeEmpty(List L)
{
    Position Tmp;

    if(L == NULL) {
        Error("Must create list first");
    }

    L->Previous = NULL;

    while(!IsEmpty(L)) {
        Tmp = L->Next;
        L->Next = Tmp->Next;
        free(Tmp);
    }

    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL && L->Previous == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

/* 插入在P的后面 */
void Insert(ElementType X, List L, Position P)
{
    PtrToNode NewNode = malloc(sizeof(struct Node));
    if(NewNode == NULL) {
        FatalError("Out of space!!!");
    }

    if(!IsLast(P, L)) {
        NewNode->Element = X;
        NewNode->Previous = P;
        NewNode->Next = P->Next;

        P->Next = NewNode;
        NewNode->Next->Previous = NewNode;
    }
    else {
        NewNode->Element = X;
        NewNode->Previous = P;
        NewNode->Next = P->Next;

        P->Next = NewNode;
    }
}
