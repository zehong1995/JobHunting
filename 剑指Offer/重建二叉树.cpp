/**
 * 题意：
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * 思路：
 * 前序遍历的第一个结点/后序遍历的最后一个结点可以将树分为左右子树。
 * 通过递归调用重建二叉树
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstruct(
        const vector<int>& pre,
        const vector<int>& vin,
        int l1, int r1, int l2, int r2) {
        if (r1 < l1 || r2 < l2) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[l1]);
        int pos = l2;
        while(vin[pos] != pre[l1]) {
            pos++;
        }
        int leftEndOfPre = l1 + pos - l2;
        root->left = reConstruct(pre, vin, l1 + 1, leftEndOfPre, l2, pos - 1);
        root->right = reConstruct(pre, vin, leftEndOfPre + 1, r1, pos + 1, r2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n = pre.size(); //空的情况包括在reConstruct里
        TreeNode* root = reConstruct(pre, vin, 0, n - 1, 0, n - 1);
        return root;
    }
};
