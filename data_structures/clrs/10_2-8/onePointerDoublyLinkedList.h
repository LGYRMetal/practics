#ifndef __ONE_POINTER_DOUBLY_LINKED_LIST__
#define __ONE_POINTER_DOUBLY_LINKED_LIST__

typedef (struct Node)* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    ElementType x;
    List np;
};

#endif /* __ONE_POINTER_DOUBLY_LINKED_LIST__ */
