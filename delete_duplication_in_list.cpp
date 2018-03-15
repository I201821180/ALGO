/*
 * 删除链表中的重复节点
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode * deleteDuplication(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
    {
        return pHead;
    }

    ListNode *pPreNode = nullptr;
    ListNode *pNode = pHead;

    while (pNode != nullptr && pNode->next != nullptr)
    {
        int needDelete = false;
        if (pNode->next->val == pNode->val)
        {
            needDelete = true;
        }

        if (!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->next;
        }
        else
        {
            int repeatValue = pNode->val;
            while (pNode != nullptr && pNode->val == repeatValue)
            {
                bool isHead = (pHead == pNode);

                ListNode *pToBeDeleted = pNode;
                pNode = pNode->next;

                if (isHead)
                {
                    pHead = pNode;
                }
                else
                {
                    pPreNode->next = pNode;
                }

                delete pToBeDeleted;
            }
        }
    }

    return pHead;
}

int main()
{
    ListNode *n1 = new ListNode(1);

    ListNode *n2 = new ListNode(1);
    n1->next = n2;

    ListNode *n3 = new ListNode(2);
    n2->next = n3;

    ListNode *n4 = new ListNode(2);
    n3->next = n4;

    ListNode *n5 = new ListNode(2);
    n4->next = n5;

    ListNode *pNode = deleteDuplication(n1);

    while (pNode != nullptr)
    {
        std::cout << pNode->val << " ";
        pNode = pNode->next;
    }
    std::cout << std::endl;

    return 0;
}
