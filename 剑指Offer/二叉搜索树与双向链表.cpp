/**
 * 题目：
 * 二叉搜索树与双向链表
 * 题意：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
 * 思路：
 * 用一个pNode指针记录中序遍历结果
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
    void dfs(TreeNode*& pre, TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        dfs(pre, root -> left);
        root -> left = pre;
        if(pre) {
            pre -> right = root;
        }
        pre = root;
        dfs(pre, root -> right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode* pre = nullptr;
        dfs(pre, pRootOfTree);
        while(pRootOfTree->left) {
            pRootOfTree = pRootOfTree -> left;
        }
        return pRootOfTree;
    }
};