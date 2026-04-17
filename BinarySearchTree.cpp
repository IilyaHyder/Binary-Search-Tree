#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *helper(std::vector<int> &arr, int st, int end)
{
    if (arr.empty())
        return nullptr;

    if (st <= end)
    {
        int mid = st + (end - st) / 2;

        TreeNode *root = new TreeNode(arr[mid]);

        root->left = helper(arr, st, mid - 1);
        root->right = helper(arr, mid + 1, end);

        return root;
    }
    return nullptr;
}

TreeNode *makeBSTfromSortedVect(std::vector<int> &arr)
{
    int st = 0;
    int end = arr.size() - 1;

    return helper(arr, st, end);
}

void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    std::cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = makeBSTfromSortedVect(arr);

    preOrder(root);

    return 0;
}