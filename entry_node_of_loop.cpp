/*
 * 链表中换的如何节点
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * meeting(ListNode *pHead)
{
    ListNode *pNode1 = pHead, *pNode2 = pHead;

    do
    {
        if (pNode1->next == nullptr || pNode2 == nullptr || pNode2->next == nullptr)
        {
            return nullptr;
        }

        pNode1 = pNode1->next;
        pNode2 = pNode2->next->next;
    }
    while(pNode1 != pNode2);

    return pNode1;
}


ListNode * EntryNodeOfLoop(ListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    ListNode *pMeeting = meeting(pHead);
    if (pMeeting == nullptr)
    {
        return nullptr;
    }

    ListNode *pNode = pMeeting->next;
    int nLoop = 1;
    while (pNode != pMeeting)
    {
        pNode = pNode->next;
        nLoop++;
    }

    ListNode *pAhead = pHead, *pBehind = pHead;
    for (int i = 0; i < nLoop; i++)
    {
        pAhead = pAhead->next;
    }

    while (pBehind != pAhead)
    {
        pBehind = pBehind->next;
        pAhead = pAhead->next;
    }

    return pAhead;
}


int main()
{
    ListNode *n1 = new ListNode(1);

    ListNode *n2 = new ListNode(2);
    n1->next = n2;

    ListNode *n3 = new ListNode(3);
    n2->next = n3;

    ListNode *n4 = new ListNode(4);
    n3->next = n4;

    ListNode *n5 = new ListNode(5);
    n4->next = n5;

    ListNode *n6 = new ListNode(6);
    n5->next = n6;

    n6->next = n3;

    ListNode *pEntry = EntryNodeOfLoop(n1);

    std::cout << pEntry->val << std::endl;

    return 0;
}

