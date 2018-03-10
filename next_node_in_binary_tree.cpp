/*
 * Get the next node in a binary tree.
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

TreeLinkNode * GetNext(TreeLinkNode *pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }


    if (pNode->right != nullptr)
    {
        TreeLinkNode *pNext = nullptr;
        pNext = pNode->right;
        while (pNext->left != nullptr)
        {
            pNext = pNext->left;
        }
        return pNext;
    }

    else if (pNode->next != nullptr)
    {
        if (pNode == pNode->next->left)
        {
            return pNode->next;
        }
        else
        {
            TreeLinkNode *pFather = pNode->next;
            while (pFather->next != nullptr)
            {
                if (pFather == pFather->next->left)
                {
                    return pFather->next;
                }
                else
                {
                    pFather = pFather->next;
                }
            }

            return nullptr;
        }
    }

    return nullptr;
}

