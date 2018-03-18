/*
 * 包含min函数的栈
 */

#include <stack>

using namespace std;

class MinStack {
public:
    void push(int value)
    {
        data_stack.push(value);

        if (min_stack.empty() || value < min_stack.top())
        {
            min_stack.push(value);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }

    void pop()
    {
        if (!min_stack.empty() && !data_stack.empty())
        {
            data_stack.pop();
            min_stack.pop();
        }
    }

    int top()
    {
        if (data_stack.empty())
        {
            throw out_of_range("Stack is empty");
        }
        return data_stack.top();
    }

    int min()
    {
        if (min_stack.empty())
        {
            throw out_of_range("Stack is empty");
        }

        return min_stack.top();
    }

private:
    stack<int> data_stack;
    stack<int> min_stack;
};

