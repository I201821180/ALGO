/*
 * 链表中的倒数第k个节点
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * FindKthToTail(ListNode * pListHead, unsigned int k)
{
    if (pListHead == nullptr || k == 0)
    {
        return nullptr;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = pListHead;

    for (unsigned int i = 0; i < k-1; i++)
    {
        if (pAhead->next == nullptr)
        {
            return nullptr;
        }

        pAhead = pAhead->next;
    }

    pAhead = pAhead->next;
    while (pAhead != nullptr)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }

    return pBehind;
}

int main()
{
    ListNode *n1 = new ListNode(1);

    ListNode *n2 = new ListNode(3);
    n1->next = n2;

    ListNode *n3 = new ListNode(5);
    n2->next = n3;

    ListNode *pNode = FindKthToTail(n1, 3);

    std::cout << pNode->val << std::endl;

    return 0;
}

