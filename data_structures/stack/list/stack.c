#include "stack.h"

/* Stack implementation is a linked list with a header */
struct Node {
    ElementType Element;
    PtrToNode   Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

/* 创建一个空栈 */
/* 我的实现，没判断malloc后的S
Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));

    S->Next = NULL;

    return S;
}*/

/* 书上的实现 */
Stack CreateStack(void)
{
    Stack S;

    S = malloc(sizeof(struct Node));
    if(S == NULL) {
        FatalError("Out of space!!!");
    }

    S->Next == NULL;
    MakeEmpty(S);

    return S;
}

void MakeEmpty(Stack S)
{
    if(S == NULL) {
        Error("Must use CreateStack first");
    }
    else {
        while(!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if(IsEmpty(S)) {
        Error("Empty stack");
    }
    else {
        FirstCell = S->Next;

        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}

/* 又忘了检测 malloc 是否成功
void Push(ElementType X, Stack S)
{
    PtrToNode NewNode;

    NewNode = malloc(sizeof(struct Node));
    NewNode->Element = X;
    NewNode->Next = S->Next;
    S->Next = NewNode;
} */

void Push(ElementType X, Stack S)
{
    PtrToNode NewNode;

    NewNode = malloc(sizeof(struct Node));
    /******** 忘了n次 *******/
    if(NewNode == NULL) {
        FatalError("Out of space!!!");
    }
    /******** 忘了n次 *******/
    else {
        NewNode->Element = X;
        NewNode->Next = S->Next;
        S->Next = NewNode;
    }
}

/* 我的实现，空栈的情况下没有返回0
ElementType Top(Stack S)
{
    if(IsEmpty(S)) {
        Error("Empty stack");
    }
    else {
        return S->Next->Element;
    }
} */

/* 书上的实现 */
ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    else
        Error("Empty stack");

    return 0; /* Return value used to avoid warning */
}
