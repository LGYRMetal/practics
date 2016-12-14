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

    printf("======== 3.2 PrintLots ========\n\n");
    /* 创建链表PL */
    List PL = CreateList();
    P = PL;
    for(int i = 1; i < 20; i += 2) {
        Insert(i, PL, P);
        /* 在列表末尾插入 */
        P = P->Next;
    }
    /* 打印链表PL的所有元素 */
    print_list(PL);

    PrintLots(L, PL);

    printf("======== 3.4 intersection =========\n\n");
    print_list(intersection(L, PL));
/*
    print_list(intersection(L, CreateList()));
 */

    printf("======== 3.3 exchange ========\n\n");
    /* 打印链表L的所有元素 */
    print_list(L);

    /* 调换链表L的第2个及其相邻的元素位置 */
    P = L->Next; /* 链表L的第一个元素位置 */
    exchange(L, P->Next/* 链表L的第2个元素的位置 */);

    print_list(L);

    printf("======== 3.5 Union ========\n\n");
    Position P1, P2;
    List L1, L2;
    L1 = CreateList();
    L2 = CreateList();

    P1 = L1;
    P2 = L2;
    for(int i = 0; i < 5; i++) {
        Insert(i, L1, P1);
        P1 = P1->Next;
    }

    for(int i = 1; i < 10; i++) {
        Insert(i, L2, P2);
        P2 = P2->Next;
    }

    printf("L1: ");
    print_list(L1);

    printf("L2: ");
    print_list(L2);

    printf("L1 union L2: ");
    print_list(Union(L1, L2));

    return 0;
}
