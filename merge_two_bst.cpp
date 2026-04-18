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

std::vector<int> inorder(TreeNode *root, std::vector<int> &tree)
{
    if (root == nullptr)
    {
        return tree;
    }

    inorder(root->left, tree);
    tree.push_back(root->val);
    inorder(root->right, tree);

    return tree;
}

std::vector<int> merge(std::vector<int> &tree1, std::vector<int> &tree2)
{
    int i = 0, j = 0;
    std::vector<int> temp;

    while (i < (int)tree1.size() && j < (int)tree2.size())
    {
        if (tree1[i] < tree2[j])
        {
            temp.push_back(tree1[i]);
            i++;
        }
        else if (tree2[j] < tree1[i])
        {
            temp.push_back(tree2[j]);
            j++;
        }
    }

    while (i < (int)tree1.size())
    {
        temp.push_back(tree1[i]);
        i++;
    }

    while (j < (int)tree2.size())
    {
        temp.push_back(tree2[j]);
        j++;
    }

    return temp;
}

TreeNode *mergeTwoBST(TreeNode *r1, TreeNode *r2)
{
    std::vector<int> tree1;
    std::vector<int> tree2;

    inorder(r1, tree1);
    inorder(r2, tree2);

    std::vector<int> arr = merge(tree1, tree2);

    return makeBSTfromSortedVect(arr);
}

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    std::vector<int> arr1 = {1, 2, 4, 5, 7, 9};

    TreeNode *root1 = makeBSTfromSortedVect(arr1);

    std::vector<int> arr2 = {0, 3, 6, 8, 10, 11};

    TreeNode *root2 = makeBSTfromSortedVect(arr2);

    TreeNode *root3 = mergeTwoBST(root1, root2);

    printInOrder(root3);

    return 0;
}