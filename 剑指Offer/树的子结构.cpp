/**
 * 题目：
 * 树的子结构
 * 题意：
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 * 思路：
 * 遍历A树递归判断
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
    bool isSubTree(TreeNode* r1, TreeNode* r2) {
        if(r2 == NULL) {
            return true;
        } else if(r1 == NULL) {
            return false;
        } else if(r1->val == r2->val) {
            return isSubTree(r1->left, r2->left) && isSubTree(r1->right, r2->right);
        } else {
            return false;
        }
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL || pRoot1 == NULL) {
            return false;
        }
        if(isSubTree(pRoot1, pRoot2)) {
            return true;
        } else {
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }
    }
};