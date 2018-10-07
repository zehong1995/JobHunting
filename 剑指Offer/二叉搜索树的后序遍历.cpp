/**
 * 题目：
 * 二叉搜索树的后序遍历
 * 题意：
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * 思路：
 * 利用二叉搜索树左子树<结点<右子树的特点，
 * 每次找到序列中第一个大于post[to]的位置pos，先判断pos->to-1是否全部严格大于post[to]
 * 若满足的话，则递归判断from->pos-1和pos->to-1是否满足二叉搜索树性质
 */
class Solution {
public:
    bool check_right(const vector<int>& post, int from, int to, int root_val) {
        for (int i = from; i <= to; ++ i) {
            if (post[i] <= root_val) {
                return false;
            }
        }
        return true;
    }
    bool isBST(const vector<int>&post, int from, int to) {
        if (from >= to) {
            return true;
        }
        int idx = from;
        while(idx < to && post[idx] < post[to]) {
            idx++;
        }
        bool flag = check_right(post, idx, to - 1, post[to]);
        flag &= isBST(post, from, idx - 1);
        flag &= isBST(post, idx, to - 1);
        return flag;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if (n == 0) {
            return false;
        } else {
            return isBST(sequence, 0, n - 1);
        }
    }
};