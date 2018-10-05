/**
 * 题目：
 * 二叉树中和为某一值的路径
 * 题意：
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * 思路：
 * 一开始题意没都清楚，以为是随意路径等于expectNumber即可，其实是要到叶子结点，所以这个问题就更简单了
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
    void UpdatePath(TreeNode* root, vector<vector<int> >& ans, vector<int>path, int sum, int expectNumber) {
        sum += root -> val;
        if(sum > expectNumber) {
            return;
        }
        path.push_back(root -> val);
        if(sum == expectNumber) {
            ans.push_back(path);
        }
        if(root -> left != NULL) {
            UpdatePath(root -> left, ans, path, sum, expectNumber);
        }
        if(root -> right != NULL) {
            UpdatePath(root -> right, ans, path, sum, expectNumber);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector< vector<int> > ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            if(top -> left != NULL) {
                q.push(top -> left);
            }
            if(top -> right != NULL) {
                q.push(top -> right);
            }
            vector<int>path;
            path.clear();
            UpdatePath(top, ans, path, 0, expectNumber);
        }
        return ans;
    }
    
};