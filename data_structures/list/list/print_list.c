/* 3.1 编写打印出一个单链表的所有元素的程序 */

#include "list.h"

void print_list(List L)
{
    Position P;

    if(L == NULL)
        Error("Must create a list first");
    if(IsEmpty(L))
        Error("Empty list");

    P = L->Next;
    while(P) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    putchar('\n');
}
