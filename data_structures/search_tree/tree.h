#ifndef _Tree_H
#define _Tree_H

#include "../../common.h"

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode {
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};

SearchTree  MakeEmpty(SearchTree T);
Position    Find(ElementType X, SearchTree T);
Position    FindMin(SearchTree T);
Position    FindMax(SearchTree T);
SearchTree  Insert(ElementType X, SearchTree T);
SearchTree  Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /* _Tree_H */
