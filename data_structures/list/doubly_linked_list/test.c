#include "test.h"

int main(int argc, char* argv[])
{
    List L;
    Position P;

    /* 创建链表 */
    L = CreateList();
    P = L;

    for(int i = 0; i < 10; i++) {
        Insert(i, L, P);
        /* 在列表末尾插入 */
        P = P->Next;
    }

    /* 打印链表L所有元素 */
    printf("======== 3.1 print_list ========\n\n");
    print_list(L);
/*
    printf("======== 3.2 PrintLots ========\n\n");
 */
    /* 创建链表PL */
/*
    List PL = CreateList();
    P = PL;
    for(int i = 1; i < 7; i += 2) {
        Insert(i, PL, P);
 */
        /* 在列表末尾插入 */
/*
        P = P->Next;
    }
 */
    /* 打印链表PL的所有元素 */
/*
    print_list(PL);

    PrintLots(L, PL);
 */

    printf("======== 3.3 exchange ========\n\n");
    /* 打印链表L的所有元素 */
    print_list(L);

    /* 调换链表L的第2个及其相邻的元素位置 */
    P = L->Next; /* 链表L的第一个元素位置 */
    exchange(L, P->Next/* 链表L的第2个元素的位置 */);
    exchange(L, P->Next->Next);

    print_list(L);

    return 0;
}
