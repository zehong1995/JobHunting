/**
 * 题目：
 * 包含min函数的栈
 * 题意：
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
 * 思路：
 * 维护一个单调栈
 */
 
class Solution {
public:
    stack<int>sta1, sta2;
    void push(int value) {
        sta1.push(value);
        if(sta2.empty()) {
            sta2.push(value);
        } else if(value <= sta2.top()) {
            sta2.push(value);
        }
    }
    void pop() {
        if(sta1.top() == sta2.top()) {
            sta1.pop();
            sta2.pop();
        } else {
            sta1.pop();
        }
    }
    int top() {
        return sta1.top();
    }
    int min() {
        return sta2.top();
    }
};