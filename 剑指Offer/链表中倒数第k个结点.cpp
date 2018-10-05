/**
 * 题目：
 * 链表中倒数第k个结点
 * 题意：
 * 输入一个链表，输出该链表中倒数第k个结点。
 * 思路：
 * 1.复制链表头，设为链表1和链表2，两链表等价。
 * 2.链表1先走k-1个节点，此后链表1链表2同时走。
 * 3.当链表1走到结尾时，对应的链表2的结点就是倒数第k个结点。
 * (拿笔比划下就比较清晰)
 */

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int cnt = 0;
        ListNode* node = pListHead;
        while(node != NULL) {
            node = node->next;
            cnt++;
            if(cnt > k) {
                pListHead = pListHead->next;
            }
        }
        if(cnt < k) return NULL;
        else return pListHead;
    }
};