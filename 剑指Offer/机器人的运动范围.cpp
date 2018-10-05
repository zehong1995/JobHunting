/**
 * 题目：
 * 机器人的运动范围
 * 题意：
 * 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
 * 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 * 思路：
 * 深搜或者广搜，注意特判(0,0)这个点
 */
 
class Solution {
public:
    bool judge(int threshold, int x, int y) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        while(y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= threshold;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        bool **vis = new bool*[rows];
        for(int i = 0; i < rows; ++ i) {
            *(vis + i) = new bool[cols];
        }
        for(int i = 0; i < rows; ++ i) {
            memset(vis[i], false, sizeof(bool) * cols);
        }
        queue<pair<int,int> >q;
		if (!judge(threshold, 0, 0)) {
            return 0;
        }
        q.push(make_pair(0, 0));
        vis[0][0] = true;
        int ans = 0;
        while(!q.empty()) {
            pair<int,int> top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            ans ++;
            for(int i = 0; i < 4; ++ i) {
                int xx = x + fx[i];
                int yy = y + fy[i];
                if(xx < 0 || yy < 0 || xx >= rows || yy >= cols || vis[xx][yy] || !judge(threshold, xx, yy)) {
                    continue;
                }
                vis[xx][yy] = true;
                q.push(make_pair(xx, yy));
            }
        }
        for(int i = 0; i < rows; ++ i) {
            delete[]vis[i];
        }
        delete []vis;
        return ans;
    }
private:
    int fx[4] = {0, 0, -1, 1};
    int fy[4] = {1, -1, 0, 0};
};
