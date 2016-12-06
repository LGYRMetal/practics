/* 3.2 给你一个链表L和另一个链表P,他们包含以升序排列的整数。操作
 * PrintLots(L, P)将打印L中那些由P所指定的位置上的元素。例如，如果
 * p = 1, 3, 4, 6, 那么，L中的第1、第3、第4和第6个元素被打印出来。写出过程
 * PrintLots(L, P)。你应该只使用基本的表操作。该过程的运行时间是多少？
 */
#include "list.h"

void PrintLots(List L, List P)
{
    Position PL, PP;
    int i = 0; /*计数器*/

    if(IsEmpty(L) || IsEmpty(P))
        Error("Empty list");

    PL = L;
    PP = P->Next;
    while(PP) {
        while(i < PP->Element && !IsLast(PL, L)) {
            PL = PL->Next;
            i++;
        }

        if(i == PP->Element)
            printf("%d ", PL->Element);
        else {
            putchar('\n');
            printf("第二个列表参数中的位置%d及之后的位置", PP->Element);
            printf("超出了第一个列表参数中的范围\n");
            return;
        }

        PP = PP->Next;
    }
    putchar('\n');
}
