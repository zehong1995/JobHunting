/**
 * 题目：
 * 二叉树的镜像
 * 题意：
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 * 二叉树的镜像定义：源二叉树 
 *    	    8
 *    	   /  \
 *    	  6   10
 *    	 / \  / \
 *    	5  7 9 11
 *    	镜像二叉树
 *    	    8
 *    	   /  \
 *    	  10   6
 *    	 / \  / \
 *    	11 9 7  5
 * 思路：
 * 层序遍历，然后替换左右子结点
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return;
        queue<TreeNode*>q;
        q.push(pRoot);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            TreeNode* l = top->left;
            TreeNode* r = top->right;
            top->right = l;
            top->left = r;
            if(l != NULL) {
                q.push(l);
            }
            if(r != NULL) {
                q.push(r);
            }
        }
    }
};