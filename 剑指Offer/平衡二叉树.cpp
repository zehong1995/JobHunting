/**
 * 题目：
 * 平衡二叉树
 * 题意：
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 * 思路：
 * dfs深搜求深度，过程计算所有子树的深度之差是否小于等于1
 */
class Solution {
public:
    int calculateDepth(TreeNode* pRoot, bool& flag) {
        if (pRoot == nullptr || flag == false) {
            return 0;
        }
        int left = calculateDepth(pRoot->left, flag);
        int right = calculateDepth(pRoot->right, flag);
        flag &= (abs(left - right) <= 1);
        return max(left, right) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool flag = true;
        int depth = calculateDepth(pRoot, flag);
        return flag;
    }
};