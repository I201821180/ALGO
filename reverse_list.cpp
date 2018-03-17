/*
 * 反转链表
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * ReverseList(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    ListNode *pNode = pHead->next;
    ListNode *pPre = pHead;
    pPre->next = nullptr;

    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->next;
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }

    return pPre;
}


int main()
{
    ListNode *n1 = new ListNode(1);

    ListNode *n2 = new ListNode(3);
    n1->next = n2;

    ListNode *n3 = new ListNode(5);
    n2->next = n3;

    ListNode *pHead = ReverseList(n1);

    std::cout << pHead->val << std::endl;

    return 0;
}

