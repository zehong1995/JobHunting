/**
 * 题目：
 * 跳台阶
 * 题意：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 思路：
 * 简单分析下，这就是一个斐波那契数列。
 * 青蛙跳到n级台阶的跳法，等于跳到n-1级的跳法（然后跳1步到达n级）加上跳到n-2级的跳法（然后它跳2步达到n级）
 * f(1) = 1， f(2) = 2…
 */
 
class Solution {
public:
    int jumpFloor(int number) {
        int pre1 = 0, pre2 = 1, ans = 0;
        while(number--) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};
