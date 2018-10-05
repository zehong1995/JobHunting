/**
 * 题目：
 * 反转链表
 * 题意：
 * 输入一个链表，反转链表后，输出链表的所有元素。
 * 思路：
 * 直接模拟，然后返回链表头。注意特判空链表。
 */

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        //特判空链表
        if(pHead == NULL) {
            return NULL;
        }
        ListNode *pre = new ListNode(pHead->val);
        ListNode *cur = pHead->next;
        while(cur != NULL) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
