#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#define true 1;
#define false 0;

typedef int bool;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct _ListNode {
    struct TreeNode* treeNode;
    struct _ListNode* Next;
};
typedef struct _ListNode* ListNode;
typedef struct _ListNode* List;
typedef struct _ListNode* Position;

typedef struct stack {
    List element;
    Position top;
} Stack;

Stack* StackCreate()
{
    Stack* s;
    Position top;

    s = malloc(sizeof(Stack));
    if(s == NULL) {
        err(-1, "line 34: StackCreate: malloc: out of space!");
    }

    s->element = malloc(sizeof(struct _ListNode));
    if(s->element == NULL) {
        err(-1, "line 39: StackCreate: malloc: out of space!");
    }
    s->element->treeNode = NULL;
    s->element->Next = NULL;

    s->top = s->element->Next;

    return s;
}

bool StackEmpty(Stack* s)
{
    if(s->top == NULL)
        return true;
    return false;
}

void Push(Stack* s, struct TreeNode* treeNode)
{
    ListNode listNode;
    listNode = malloc(sizeof(struct _ListNode));
    if(listNode == NULL) {
        err(-1, "line 60: Push: malloc: out of space!");
    }
    listNode->treeNode = treeNode;
    listNode->Next = s->element->Next;

    s->element->Next = listNode;
    s->top = listNode;
}

struct TreeNode* Pop(Stack* s)
{
    Position p;
    struct TreeNode* treeNode;

    if(StackEmpty(s)) {
        err(-1, "Stack underflow!");
    }

    p = s->top;
    s->element->Next = p->Next;
    s->top = p->Next;
    
    treeNode = p->treeNode;

    free(p);
    p = NULL;

    return treeNode;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    Stack* s;
    struct TreeNode* tmp;

    s = StackCreate();

    Push(s, root);
    while(!StackEmpty(s)) {
        tmp = Pop(s);
        if(tmp && (tmp->left || tmp->right)) {
            tmp->left =(struct TreeNode*)((int)tmp->left ^ (int)tmp->right);
            tmp->right=(struct TreeNode*)((int)tmp->left ^ (int)tmp->right);
            tmp->left =(struct TreeNode*)((int)tmp->left ^ (int)tmp->right);

            if(tmp->left) {
                Push(s, tmp->left);
            }
            if(tmp->right) {
                Push(s, tmp->right);
            }
        }
    }

    return root;
}
