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
 * 思路2，(同理，只不过自己不小心写了2次又不忍心删掉)：
 * 双指针，p1=p2=pHead，p1先走k-1步，然后p1p2再一起走，当p2走到最后的结点时，p1就是倒数第k个结点
 * 注意k可以为0，或者k可以大于链表长度
 * 综上，用一个cnt来计数，当cnt>k时，p2开始走，若cnt<k说明k大于链表长度，否则返回p1
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