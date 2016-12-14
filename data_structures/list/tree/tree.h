typedef struct TreeNode *PtrToNOde;

struct TreeNode {
    ElementType Element;
    PtrToNode   FirstChild;
    PtrToNode   NextSibling;
};
