/*
 * 合并两个排序的链表
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr && pHead2 == nullptr)
    {
        return nullptr;
    }
    else if (pHead1 == nullptr && pHead2 != nullptr)
    {
        return pHead2;
    }
    else if (pHead1 != nullptr && pHead2 == nullptr)
    {
        return pHead1;
    }

    ListNode *pHead = nullptr;
    if (pHead1->val < pHead2->val)
    {
        pHead = pHead1;
        pHead->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        pHead = pHead2;
        pHead->next = Merge(pHead1, pHead2->next);
    }

    return pHead;
}

