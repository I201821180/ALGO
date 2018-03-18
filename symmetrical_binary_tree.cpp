/*
 * 对称的二叉树
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
    {
        return true;
    }
    else if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }
    else if (pRoot1->val != pRoot2->val)
    {
        return false;
    }

    return isSymmetrical(pRoot1->left, pRoot2->right)
        && isSymmetrical(pRoot1->right, pRoot2->left);
}

bool isSymmetrical(TreeNode *pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

