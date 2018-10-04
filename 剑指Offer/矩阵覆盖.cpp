/**
 * 题目：
 * 矩形覆盖
 * 题意：
 * 我们可以用21的小矩形横着或者竖着去覆盖更大的矩形。请问用n个21的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 思路：
 * 思路和青蛙跳楼梯一样。
 */

class Solution {
public:
    int rectCover(int number) {
        int pre1 = 0, pre2 = 1, ans = 0;
        for(int i = 0; i < number; ++ i) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};
