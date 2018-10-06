/**
 * 题目：
 * 调整数组顺序使奇数位于偶数前面
 * 题意：
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * 思路：
 * 插入排序 or STL
 * 插入排序思想在这里的复杂度是O(2N)而不是O(N2)
 */
 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int n = array.size();
        int i, j;
        for(i = 0; i < n; ++ i) {
            if(array[i] % 2 != 0) {
                int tmp = array[i];
                for(j = i - 1; j >= 0; -- j) {
                    if(array[j] % 2 == 0) {
                        array[j + 1] = array[j];
                    } else {
                        break;
                    }
                }
                array[j + 1] = tmp;
            }
        }
    }
};

bool cmp(int x) { //奇数返回真
    return (x & 1) == 1;
}
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(),array.end(),cmp);
    }
};
