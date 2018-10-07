/**
 * 题目：
 * 序列化二叉树
 * 题意：
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 * 思路：
 * 假设val不存在-1这个值，拿-1来做nullptr，前序遍历存进vector，将vector值写进int*数组
 * 将int*使用reinterpret_cast强制转换为char*
 * 同理，将char*转换为int*后，反前序遍历即可
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
    void doSerialize(TreeNode* root, vector<int>&v) {
        if (root == nullptr) {
            v.push_back(-1);
        } else {
            v.push_back(root->val);
            doSerialize(root->left, v);
            doSerialize(root->right, v);
        }
    }
    TreeNode* doDeserialize(int* &num) {
        if (*num == -1) {
            num++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(*num);
        num++;
        root->left = doDeserialize(num);
        root->right = doDeserialize(num);
        return root;
    }
    char* Serialize(TreeNode *root) {
        vector<int>v;
        doSerialize(root, v);
        int bufSize = v.size();
        int* num = new int[bufSize];
        for (int i = 0; i < bufSize; ++ i) {
            num[i] = v[i];
        }
        return reinterpret_cast<char*>(num);
    }
    TreeNode* Deserialize(char *str) {
        int* num = reinterpret_cast<int*>(str);
        return doDeserialize(num);
    }
};