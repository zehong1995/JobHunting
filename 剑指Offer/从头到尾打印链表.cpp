/**
* 题目：
* 从头到尾打印链表
* 题意：
* 输入一个链表，从尾到头打印链表每个节点的值。
* 思路：
* 考察链表，直接push_back，然后reverse一下。
* reverse复杂度是O(N)，比insert(ans.begin(), val)快得多。
**/


/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <algorithm>
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>ans;
        while(head != NULL) {
            ans.push_back(head->val);
            //ans.insert(ans.begin(), head->val); //复杂度太高，慎用
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//直接深搜也可以
class Solution {
public:
    void dfs(ListNode* head, vector<int>& ans) {
        if (head == NULL) {
            return;
        }
        dfs(head->next, ans);
        ans.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>ans;
        dfs(head, ans);
        return ans;
    }
};
