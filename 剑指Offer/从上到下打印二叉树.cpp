/**
 * 题目：
 * 从上往下打印二叉树
 * 题意：
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * 思路：
 * 用队列实现层序遍历
 */

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            ans.push_back(top->val);
            if(top -> left != NULL) {
                q.push(top -> left);
            }
            if(top -> right != NULL) {
                q.push(top -> right);
            }
        }
        return ans;
    }
};