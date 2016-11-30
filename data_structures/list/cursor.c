#include "cursor.h"

struct Node {
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}

int IsEmpty(const List L)
{
    return CursorSpace[L].Next == 0;
}

int IsLast(const Position P, const List L)
{
    return CursorSpace[P].Next == 0;
}

Position Find(ElementType X, const List L)
{
    Position P;

    P = CursorSpace[L].Next;
    /* while(P && CursorSpace[P].Element != X) 书上的实现 */
    while(P != 0 && CursorSpace[P].Element != X) {
        P = CursorSpace[P].Next;
    }

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!IsLast(P, L)) {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

Position FindPrevious(ElementType X, const List L)
{
    Position P;

    P = L;
    while(CursorSpace[P].Next != 0 &&
          CursorSpace[CursorSpace[P].Next].Element != X) {
        P = CursorSpace[P].Next;
    }

    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position Tmp;
    Tmp = CursorAlloc();

    /* 缺少判断 Tmp */
    if(Tmp == 0)
        FatalError("Out of space!!!");
    /* 缺少判断 Tmp */

    CursorSpace[Tmp].Element = X;
    CursorSpace[Tmp].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = Tmp;
}

int main(void)
{
    /* For Test */
}
