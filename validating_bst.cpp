#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode *root, TreeNode *min, TreeNode *max)
{
    if (root == nullptr)
        return true;
    if (min != nullptr && root->val <= min->val)
        return false;
    if (max != nullptr && root->val >= max->val)
        return false;

    return helper(root->left, min, root) &&
           helper(root->right, root, max);
}

bool isBST(TreeNode *root)
{
    TreeNode *min = nullptr;
    TreeNode *max = nullptr;

    return helper(root, min, max);
}

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

int main()
{

    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = makeBSTfromSortedVect(arr);

    std::cout << isBST(root) << std::endl;

    return 0;
}