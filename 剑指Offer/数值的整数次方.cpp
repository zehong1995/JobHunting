/**
 * 题目：
 * 数值的整数次方
 * 题意：
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 思路：
 * 快速幂。注意负数。
 */
class Solution {
public:
    double Power(double base, int exponent) {
        double ans = 1.0;
        int n = abs(exponent);
        while(n) {
            if(n & 1) {
                ans = ans * base;
            }
            base = base * base;
            n >>= 1;
        }
        if(exponent < 0) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};