/*
 * 二叉树的广度优先遍历
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> PrintFromTopToBottom(TreeNode *root)
{
    vector<int> result;

    if (root == nullptr)
    {
        return result;
    }

    deque<TreeNode *> queue = {root};

    while (!queue.empty())
    {
        TreeNode *pNode = queue.front();
        queue.pop_front();
        result.push_back(pNode->val);

        if (pNode->left != nullptr)
        {
            queue.push_back(pNode->left);
        }

        if (pNode->right != nullptr)
        {
            queue.push_back(pNode->right);
        }
    }

    return result;
}

