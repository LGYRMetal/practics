/* 非ADT风格 */
#include "stack.h"

/* Stack implementation is a dynamically allocated array */
#define EmptyTOS        (-1)
#define MinStackSize    (5)

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

/* 我的实现没判断MaxElements是否小于MinStackSize,S->Array是先初始化一个数组
 * 再赋值给S->Array，不知道对不对
Stack CreateStack(int MaxElements)
{
    Stack S;
    ElementType A[MaxElements];

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL) {
        FatalError("Out of space!!!");
    }
    for(int i = 0; i < MaxElements; i++) {
        A[i] = 0;
    }

    S->Capacity   = MaxElements;
    S->TopOfStack = EmptyTOS;
    S->Array      = A;

    return S;
} */

/* 书上的实现更好一点吧 */
Stack CreateStack(int MaxElements)
{
    Stack S;

    if(MaxElements < MinStackSize) {
        Error("Stack size is too small");
    }

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL) {
        FatalError("Out of space!!!");
    }

    S->Capacity = MaxElements;
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL) {
        FatalError("Out of space!!!");
    }

    MakeEmpty(S);

    return S;
}

/* 我的实现
void MakeEmpty(Stack S)
{
    if(S == NULL) {
        Error("Create stack first!");
    }

    while(!IsEmpty(S)) {
        Pop(S);
    }
}*/

/* 下面的纯ADT实现和这个一样，重复定义了
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}*/

void DisposeStack(Stack S)
{
    if(S != NULL) {
        free(S->Array);
        free(S);
    }
}

/* 纯ADT风格的栈(数组实现的栈) */
int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

/* 没判断stack是否已满
void Push(ElementType X, Stack S)
{
    S->Array[++(S->TopOfStack)] = X;
} */

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Stack is full");
    else
        S->Array[++(S->TopOfStack)] = X;
}

/* S为空栈的时候又没有返回0
ElementType Top(Stack S)
{
    if(IsEmpty(S))
        Error("Empty stack");
    else
        return S->Array[S->TopOfStack];
}*/

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    else
        Error("Empty stack");

    return 0; /* Return value used to avoid warning */
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty stack");
    else
        S->TopOfStack--;
}

/*
ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    else *//* else 可以去掉, 见下面*//*
        Error("Empty stack");

    return 0; *//* Return value used to avoid warning */
/*}*/

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];

    Error("Empty stack");
    return 0; /* Return value used to avoid warning */
}
