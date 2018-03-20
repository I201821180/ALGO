/*
 * 二叉树中和为某一值的路径
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void find_path_core(TreeNode *root, int expectNumber, int sum,
                    vector<int> path, vector<vector<int> > & all_paths)
{
    if (root->left == nullptr && root->right == nullptr && sum + root->val == expectNumber)
    {
        path.push_back(root->val);
        all_paths.push_back(path);

        return;
    }

    if (sum + root->val > expectNumber)
    {
        return;
    }

    path.push_back(root->val);
    sum += root->val;

    if (root->left != nullptr)
    {
        find_path_core(root->left, expectNumber, sum, path, all_paths);
    }

    if (root->right != nullptr)
    {
        find_path_core(root->right, expectNumber, sum, path, all_paths);
    }
}

vector<vector<int> > FindPath(TreeNode *root, int expectNumber)
{
    vector<vector<int> > all_paths;

    if (root == nullptr)
    {
        return all_paths;
    }

    int sum = 0;
    vector<int> path;

    find_path_core(root, expectNumber, sum, path, all_paths);

    return all_paths;
}

