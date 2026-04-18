#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *prev = nullptr;
TreeNode *first = nullptr;
TreeNode *second = nullptr;
void inorderSeq(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderSeq(root->left);

    if (prev != nullptr && prev->val > root->val)
    {
        if (first == nullptr)
            first = prev;

        second = root;
    }

    prev = root;

    inorderSeq(root->right);
}

void recoverBST(TreeNode *root)
{
    inorderSeq(root);

    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}

int main()
{
    TreeNode *root; // create a tree that has atmost two wrongly placed elements;
    recoverBST(root);

    return 0;
}