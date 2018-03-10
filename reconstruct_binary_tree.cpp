/*
 * C++ implementation for the reconstruction of binary tree.
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// Define binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor.
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode * reconstruct_binary_tree(std::vector<int> pre, std::vector<int> vin)
{
    if (pre.size() == 0 || vin.size() == 0)
    {
        return nullptr;
    }

    int root_val = pre[0];
    TreeNode *root = new TreeNode(root_val);

    if (pre.size() == 1)
    {
        if (pre.size() == vin.size() && pre[0] == vin[0])
        {
            return root;
        }
        else
        {
            throw std::invalid_argument("Invalid input.");
        }
    }

    // Create subtree
    auto proot_vin = std::find(vin.begin(), vin.end(), root_val);
    if (proot_vin == vin.end())
    {
        throw std::invalid_argument("Invalid input.");
    }

    std::vector<int> left_vin, right_vin, left_pre, right_pre;
    // Left inroder.
    for (auto it = vin.begin(); it != proot_vin; it++)
    {
        left_vin.push_back(*it);
    }
    // Right inroder.
    for (auto it = proot_vin + 1; it != vin.end(); it++)
    {
        right_vin.push_back(*it);
    }
    // Left preorder.
    for (size_t i = 1; i <= left_vin.size(); i++)
    {
        left_pre.push_back(pre[i]);
    }
    for (size_t i = left_vin.size() + 1; i < pre.size(); i++)
    {
        right_pre.push_back(pre[i]);
    }

    root->left = reconstruct_binary_tree(left_pre, left_vin);
    root->right = reconstruct_binary_tree(right_pre, right_vin);

    return root;
}

void print_preorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    std::cout << root->val << std::endl;
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    print_inorder(root->left);
    std::cout << root->val << std::endl;
    print_inorder(root->right);
}

int main()
{
    std::vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};

    TreeNode *root = reconstruct_binary_tree(pre, vin);

    std::cout << "preorder: " << std::endl;
    print_preorder(root);
    std::cout << "inorder: " << std::endl;
    print_inorder(root);

    return 0;
}

