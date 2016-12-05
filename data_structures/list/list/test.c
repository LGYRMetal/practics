#include "test.h"

int main(int argc, char* argv[])
{
    List L;
    Position P;

    L = CreateList();
    P = L;

    for(int i = 0; i < 10; i++) {
        Insert(i, L, P);
        P = P->Next;
    }

    print_list(L);

    return 0;
}
