/**
 * 题目：
 * 合并两个排序的链表
 * 题意：
 * 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 * 思路：
 * 和归并排序一样，模拟后返回链表头。但根据链表的特性，后面只需要两个if就可以，不用再遍历
 */
 
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(pHead1 != NULL && pHead2 != NULL) {
            if(pHead1->val < pHead2->val) {
                cur->next = pHead1;
                cur = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                cur = pHead2;
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 != NULL) {
            cur->next = pHead1;
        }
        if (pHead2 != NULL) {
            cur->next = pHead2;
        }
        return head->next;
    }
};