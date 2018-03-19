/*
 * 栈的压入和弹出序列
 */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    if (pushV.size() == 0 || popV.size() == 0 || popV.size() != pushV.size())
    {
        return false;
    }

    stack<int> aux;
    int len_push = pushV.size();
    int len_pop = popV.size();
    int push_i = 0, pop_i = 0;

    while (push_i < len_push)
    {
        do
        {
            aux.push(pushV[push_i++]);
        }
        while (!aux.empty() && aux.top() != popV[pop_i] && push_i < len_push);

        while (aux.top() == popV[pop_i])
        {
            aux.pop();
            pop_i++;

            if (aux.empty() || pop_i >= len_pop)
            {
                break;
            }
        }
    }

    if (aux.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> pushV = {1, 2, 3, 4, 5};
    vector<int> popV = {4, 3, 5, 1, 2};

    if (IsPopOrder(pushV, popV))
    {
        cout << "is pop order" << endl;
    }
    else
    {
        cout << "not pop order" << endl;
    }

    return 0;
}

