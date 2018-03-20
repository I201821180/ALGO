/*
 * 复杂链表的复制
 */

#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next;
    RandomListNode *random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

RandomListNode * Clone(RandomListNode *pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }

    map<RandomListNode *, RandomListNode *> node_map;

    RandomListNode *pNode = pHead;
    RandomListNode *pHeadClone = new RandomListNode(pNode->label);
    RandomListNode *pNodeClone = pHeadClone;

    while (pNode != nullptr)
    {
        node_map[pNodeClone] = pNode;

        if (pNode->next != nullptr)
        {
            pNodeClone->next = new RandomListNode(pNode->next->label);
        }

        pNode = pNode->next;
        pNodeClone = pNodeClone->next;
    }

    pNodeClone = pHeadClone;
    while (pNodeClone != nullptr)
    {
        pNode = node_map[pNodeClone];
        if (pNode->random != nullptr)
        {
            pNodeClone->random = new RandomListNode(pNode->random->label);
        }
        pNodeClone = pNodeClone->next;
    }

    return pHeadClone;
}

