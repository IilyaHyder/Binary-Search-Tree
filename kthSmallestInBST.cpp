#include <iostream>

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

int count = 0;

int kthSmallest(Node *root, int k)
{
    if (root == nullptr)
        return -1;

    if (root->left)
    {
        int left_val = kthSmallest(root->left, k);
        if (left_val != -1)
            return left_val;
    }

    if (count + 1 == k)
        return root->val;

    count++;

    if (root->right)
    {
        int right_val = kthSmallest(root->right, k);
        if (right_val != -1)
            return right_val;
    }

    return -1;
}

int main()
{
    Node *root = new Node(5); // create a tree that is done in building_BinarySearchTree.cpp

    return 0;
}