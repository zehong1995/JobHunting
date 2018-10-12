#include <bits/stdc++.h>
using namespaces std;
int main() {

}
/*

链接：https://www.nowcoder.com/questionTerminal/35e3c649f05945e5898653d0697202c1
来源：牛客网

//合并 
//链表结构
struct ListNode
{
    int value;
    ListNode* next;
};
 
//合并
ListNode* merge(ListNode *a,ListNode *b)
{
    ListNode *result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
     
    if(a->value<=b->value) 
    { 
        result=a; 
        result->next=merge(a->next,b); 
    } 
    else 
    { 
        result=b; 
        result->next=merge(a,b->next);    
    } 
    return result; 
}
 
//寻找中点
void findMid(ListNode* source, ListNode** first, ListNode** mid) 
{ 
    ListNode* fast; 
    ListNode* slow; 
   
    if(source==NULL||source->next== NULL) 
    { 
        *first=source; 
        *mid=NULL; 
    } 
    else 
    { 
        slow=source; 
        fast=source->next; 
    
        while(fast!=NULL) 
        { 
            fast=fast->next; 
            if(fast!=NULL) 
            { 
                fast=fast->next; 
                slow=slow->next; 
            } 
        } 
   
        *first=source; 
        *mid=slow->next; 
        slow->next=NULL; 
    } 
} 
 
void listMergeSort(ListNode **p)
{
    ListNode *head=*p;
    ListNode *a,*b;
     
    if(head==NULL||head->next==NULL)
        return ;
     
    findMid(head,&a,&b);
     
    listMergeSort(&a);
    listMergeSort(&b);
     
    *p=merge(a,b);
}

*/
