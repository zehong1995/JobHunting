/**
 * 题目：
 * 把二叉树打印成多行
 * 题意：
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 * 思路：
 * 先计算深度，求出ans的大小，然后层序遍历，queue维护结点指针和层数信息
 */
 /*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> >ans;
            if(pRoot == NULL) {
                return ans;
            }
            int depth = 0;
            GetDepth(pRoot, 0, depth);
            vector<int>*v = new vector<int>[depth];
            queue< pair<TreeNode*, int> >q;
            q.push(make_pair(pRoot, 0));
            while(!q.empty()) {
                pair<TreeNode*, int> top = q.front();
                q.pop();
                TreeNode* node = top.first;
                v[top.second].push_back(node -> val);
                if(node -> left) {
                    q.push(make_pair(node -> left, top.second + 1));
                }
                if(node -> right) {
                    q.push(make_pair(node -> right, top.second + 1));
                }
            }
            for(int i = 0; i < depth; ++ i) {
                ans.push_back(v[i]);
            }
            return ans;
        }
        void GetDepth(TreeNode* pRoot, int cur, int& ans) {
            if(pRoot == NULL) {
                ans = max(ans, cur);
                return;
            }
            GetDepth(pRoot -> left, cur + 1, ans);
            GetDepth(pRoot -> right, cur + 1, ans);
        }
    
};