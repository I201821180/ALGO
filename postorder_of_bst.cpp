/*
 * 二叉树搜索树的后序遍历序列
 */

#include <vector>
#include <iostream>

using namespace std;

bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.size() == 0)
    {
        return false;
    }

    if (sequence.size() == 1)
    {
        return true;
    }

    int v_root = sequence[sequence.size()-1];

    bool reach_right_subtree = false;
    for (size_t i = 0; i < sequence.size()-1; i++)
    {
        if (!reach_right_subtree && sequence[i] > v_root)
        {
            reach_right_subtree = true;
        }

        if (reach_right_subtree && sequence[i] < v_root)
        {
            return false;
        }
    }

    vector<int> sub_seq(sequence.begin(), sequence.end()-1);
    return VerifySquenceOfBST(sub_seq);
}

int main()
{
    vector<int> seq = {7, 4, 6, 5};

    if (VerifySquenceOfBST(seq))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}

