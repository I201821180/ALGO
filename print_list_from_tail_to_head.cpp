/*
 * C++ implementation for printing list from tail to head.
 */

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
        val(x),
        next(nullptr)
    {}
};

std::vector<int> printListFromTailToHead(ListNode* head)
{
    std::vector<int> values;

    if (head != nullptr)
    {
        ListNode *pNode = head;

        while (pNode != nullptr)
        {
            values.insert(values.begin(), pNode->val);
            pNode = pNode->next;
        }
    }
    return values;
}

int main()
{
    ListNode *head = new ListNode(10);
    ListNode *p2 = new ListNode(5);
    head->next = p2;
    ListNode *p3 = new ListNode(6);
    p2->next = p3;

    std::vector<int> values = printListFromTailToHead(head);

    for (size_t i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
    }
    std::cout << std::endl;
}
