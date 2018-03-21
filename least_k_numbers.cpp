/*
 * 最小的k个数
 */

#include <set>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> result;

    if ((int)input.size() < k || k <= 0)
    {
        return result;
    }

    multiset<int, greater<int> > knumbers;

    for (auto it = input.begin(); it != input.end(); it++)
    {
        if (knumbers.size() < (size_t)k)
        {
            knumbers.insert(*it);
        }
        else
        {
            if (*it < *knumbers.begin())
            {
                knumbers.erase(knumbers.begin());
                knumbers.insert(*it);
            }
        }
    }

    for (auto it = knumbers.begin(); it != knumbers.end(); it++)
    {
        result.push_back(*it);
    }

    return result;
}

int main()
{
    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> topk = GetLeastNumbers_Solution(input, 4);

    for (auto it = topk.begin(); it != topk.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}

