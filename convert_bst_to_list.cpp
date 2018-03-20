/*
 * 二叉搜索树转换成双向链表
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void convert_core(TreeNode *pRoot, TreeNode* & pFirst, TreeNode* & pLast)
{
    if (pRoot->left == nullptr && pRoot->right == nullptr)
    {
        pFirst = pLast = pRoot;
        return;
    }

    TreeNode *pFirstLeft = nullptr;
    TreeNode *pLastLeft = nullptr;
    TreeNode *pFirstRight = nullptr;
    TreeNode *pLastRight = nullptr;

    if (pRoot->left != nullptr)
    {
        convert_core(pRoot->left, pFirstLeft, pLastLeft);
        pRoot->left = pLastLeft;
        pLastLeft->right = pRoot;
    }
    else
    {
        pFirstLeft = pLastLeft = pRoot;
    }

    if (pRoot->right != nullptr)
    {
        convert_core(pRoot->right, pFirstRight, pLastRight);
        pRoot->right = pFirstRight;
        pFirstRight->left = pRoot;
    }
    else
    {
        pFirstRight = pLastRight = pRoot;
    }

    pFirst = pFirstLeft;
    pLast = pLastRight;
}

TreeNode * Convert(TreeNode * pRootOfTree)
{
    if (pRootOfTree == nullptr)
    {
        return nullptr;
    }

    TreeNode *pFirst = nullptr;
    TreeNode *pLast = nullptr;

    convert_core(pRootOfTree, pFirst, pLast);

    return pFirst;
}

