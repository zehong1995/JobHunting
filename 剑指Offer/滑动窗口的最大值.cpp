/**
 * 题目：
 * 滑动窗口的最大值
 * 题意：
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 * {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 思路：
 * 用双向队列维护窗口大小的不递减队列，队首即为最大值。
 */
 
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int n = num.size();
        deque<int>dq;  //单调递减双向队列
        vector<int>ans;
        if (size == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++ i) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            while(!dq.empty() && i >= dq.front() + size) {  //注意不能用i-size，因为size是无符号数
                dq.pop_front();
            }
            dq.push_back(i);
            if (i + 1 >= size) {
                ans.push_back(num[dq.front()]);
            }
        }
        return ans;
    }
};
