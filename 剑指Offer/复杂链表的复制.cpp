/**
 * 题目：
 * 复杂链表的复制
 * 题意：
 * 输入一个复杂链表：每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点。
 * 返回结果为复制后复杂链表的head。
 * 注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空
 * 思路：
 * 1.复制next    A->B->C  A->AA->B->BB->CC
 * 2.复制random
 * 3.拆分得到A->B->C 和 AA->BB->CC
 * 此外，要特别注意几个nullptr的特判
 */

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void copyListNode(RandomListNode* pNode) {
        while(pNode != nullptr) {
            RandomListNode* nxtNode = new RandomListNode(pNode->label);
            nxtNode->next = pNode->next;
            pNode->next = nxtNode;
            pNode = nxtNode->next;
        }
    }
    void linkListNode(RandomListNode* pNode) {
        while(pNode != nullptr) {
            RandomListNode *nxtNode = pNode->next;
            nxtNode->random = pNode->random ? pNode->random->next : nullptr;
            pNode = nxtNode->next;
        }
    }
    RandomListNode* splitListNode(RandomListNode* pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }
        RandomListNode* qHead = pNode->next;
        RandomListNode* qNode = qHead;
        while(pNode != nullptr) {
            pNode->next = qNode->next;
            pNode = pNode->next;
            qNode->next = pNode ? pNode->next : nullptr;
            qNode = qNode ? qNode->next : nullptr;
        }
        return qHead;
    }
    RandomListNode* Clone(RandomListNode* pHead){
        copyListNode(pHead);
        linkListNode(pHead);
        return splitListNode(pHead);
    }
};