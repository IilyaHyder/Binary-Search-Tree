#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lca(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lca(root->right, p, q);
    else
        return root;
}