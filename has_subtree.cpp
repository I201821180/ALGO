/*
 * 树的子结构
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool has_tree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot2 == nullptr)
    {
        return true;
    }

    if (pRoot1 == nullptr)
    {
        return false;
    }

    if (pRoot1->val != pRoot2->val)
    {
        return false;
    }

    return has_tree(pRoot1->left, pRoot2->left) && has_tree(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }

    bool result = false;

    if (pRoot1->val == pRoot2->val)
    {
        result = has_tree(pRoot1, pRoot2);
    }
    
    if (!result)
    {
        result = HasSubtree(pRoot1->left, pRoot2);
    }

    if (!result)
    {
        result = HasSubtree(pRoot1->right, pRoot2);
    }

    return result;
}

