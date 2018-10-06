/**
 * 题目：
 * 删除链表中重复的结点
 * 题意:
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
 * 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * 思路：
 * 若cur和cur->next的val相等，则一直循环至下一个非val的结点
 * 根据这个，并特别注意边界问题，通过三个while嵌套循环即可写出本题
 */
 
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
ListNode* deleteDuplication(ListNode* pHead) {
    ListNode* curNode = pHead;
    ListNode* preNode = new ListNode(0);
    ListNode* ansNode = preNode;
    while(curNode != nullptr) {
        while (curNode != nullptr && curNode->next != nullptr && curNode->val == curNode->next->val) {
            int val = curNode->val;
            while(curNode != nullptr && curNode->val == val) {
                curNode = curNode->next;
            }
        }
        preNode->next = curNode;
        if (curNode != nullptr) {
            preNode = preNode->next;
            curNode = curNode->next;
        }
    }
    return ansNode->next;
}
int main() {
    ListNode* head = new ListNode(0);
    int num[] = {1, 3, 3, 4, 4, 5, 5};
    ListNode* cur = head;
    for (int i = 0; i < 7; ++ i) {
        cur -> next = new ListNode(num[i]);
        cur = cur -> next;
    }
    head = deleteDuplication(head->next);
    while(head) {
        cout << head->val << endl;
        head = head->next;
    }
}
