/**
 * 题目：
 * 矩阵中的路径
 * 题意：
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
 * 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
 * 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
 * 思路：
 * DFS直接暴力搜索
 */
 
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(strlen(str) == 0) {
            return true;
        }
        int n = strlen(matrix);
        bool *vis = new bool[rows * cols];
        memset(vis, false, sizeof(bool) * rows * cols);
        for(int i = 0; i < n; ++ i) {
            if(matrix[i] == str[0]
               && dfs(i / cols, i % cols, vis, matrix, rows, cols, str)) {
                return true;
            }
        }
        return false;
    }
    bool dfs(int x, int y, bool* vis, char* matrix, int rows, int cols, char* str) {
        if (strlen(str) < 2) {
            return true;
        }
        vis[x * cols + y] = true;
        bool flag = false;
        for (int i = 0; i < 4; ++ i) {
            int xx = x + fx[i];
            int yy = y + fy[i];
            int pos = xx * cols + yy;
            if(str[1] == matrix[pos] && vis[pos] == false) {
                flag |= dfs(xx, yy, vis, matrix, rows, cols, str + 1);
            }
        }
        vis[x * cols + y] = false;
        return flag;
    }
private:
    int fx[4] = {0, 0, -1, 1};
    int fy[4] = {1, -1, 0, 0};
};