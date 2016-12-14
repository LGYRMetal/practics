#include "tree.h"

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    Position P;

    if(T == NULL)
        return NULL;

    P = T;
    while(P && P->Element != X) {
        if(X < P->Element) {
            P = P->Left;
        }
        else {
            P = P->Right;
        }
    }

    return P;
}

Position FindMin(SearchTree T)
{
    Position P;

    if(T == NULL) {
        return NULL;
    }

    P = T;
    while(P->Left) {
        P = P->Left;
    }

    return P;
}

Position FindMax(SearchTree T)
{
    Position P;

    if(T == NULL) {
        return NULL;
    }

    P = T;
    while(P->Right) {
        P = P->Right;
    }

    return P;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else {
        if(X < T->Element) {
            T->Left = Insert(X, T->Left);
        }
        else if(X > T->Element) {
            T->Right = Insert(X, T->Right);
        }
    }

    return T;
}

#if 0 /* 书上的版本更精简 */
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpNode;

    if(T == NULL)
        /* return NULL; */
        Error("Element not found");
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
        T->Right = Delete(X, T->Right);
    else {
        if(T->Left == NULL && T->Right == NULL) { /* 树叶 */
            free(T);
            T = NULL;
        }
        else if(T->Left != NULL && T->Right == NULL) { /* 只有一个左节点 */
            TmpNode = T->Left;
            free(T);
            T = TmpNode;
        }
        else if(T->Left == NULL && T->Right != NULL) { /* 只有一个右节点 */
            TmpNode = T->Right;
            free(T);
            T = TmpNode;
        }
        else { /* 包含两个节点 */
            TmpNode = T;
            T = FindMin(T->Right);
            T->Left = TmpNode->Left;
            T->Right = Delete(T->Element, T->Right);
            free(TmpNode);
        }
    }

    return T;
}
#endif

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpNode;

    if(T == NULL)
        Error("Element not found");
    else if(X < T->Element) /* Go left */
        T->Left = Delete(X, T->Left);
    else if(X > T->Element) /* Go Right */
        T->Right = Delete(X, T->Right);
    else { /* 找到要删除的元素，删除 */
        if(T->Left && T->Right) { /* 两个子节点 */
            /* 用右子树的最小元素替换该节点 */
            TmpNode = FindMin(T->Right);
            T->Element = TmpNode->Element;
            T->Right = Delete(T->Element, T->Right);
        }
        else { /* 一个或零个子节点 */
            TmpNode = T;

            if(T->Left == NULL) /* 包含了有0个节点的情况 */
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;

            free(TmpNode);
        }
    }

    return T;
}
