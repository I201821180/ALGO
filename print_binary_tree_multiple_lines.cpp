/*
 * 分行从上到下打印二叉树
 */

#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

vector<vector<int> > Print(TreeNode *pRoot)
{
    vector<vector<int> > result;

    if (pRoot == nullptr)
    {
        return result;
    }

    deque<TreeNode *> queue = {pRoot};
    int ncurrent = 1;
    int nnext = 0;
    vector<int> line;

    while (!queue.empty())
    {
        TreeNode *pNode = queue.front();
        queue.pop_front();
        line.push_back(pNode->val);
        ncurrent--;

        if (pNode->left != nullptr)
        {
            nnext++;
            queue.push_back(pNode->left);
        }

        if (pNode->right != nullptr)
        {
            nnext++;
            queue.push_back(pNode->right);
        }

        if (ncurrent == 0)
        {
            result.push_back(line);
            line = vector<int>();
            ncurrent = nnext;
            nnext = 0;
        }
    }

    return result;
}

