/**
 * 题目：
 * 斐波那契数列
 * 题意：
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。 n<=39
 * 思路：
 * 简单递推，不要用递归，爆内存。
 * 如果不是函数限制，把所有结果一次求出来存到数组更好。
 * 当然，用矩阵快速幂也可以
 */
class Solution {
public:
    int Fibonacci(int n) {
        int pre1 = 1, pre2 = 0, ans = 0;
        while(n--) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};