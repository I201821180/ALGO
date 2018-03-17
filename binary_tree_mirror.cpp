/*
 * 二叉树镜像
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Mirror(TreeNode *pRoot)
{
    if (pRoot == nullptr)
    {
        return;
    }

    TreeNode *pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;

    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

