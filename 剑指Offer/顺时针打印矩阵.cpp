/**
 * 题目：
 * 顺时针打印矩阵
 * 题意：
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 * 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 思路：
 * 一圈一圈打印，控制边界即可
 */
 
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>ans;
        int left = 0, right = (int)matrix[0].size() - 1;
        int top = 0, bottom = (int)matrix.size() - 1;
        while(left <= right && top <= bottom) {
            for (int i = left; i <= right; ++ i) { //top
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; ++ i) { //right
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top > bottom || left > right) {  //already done with the task
                break;
            }
            for (int i = right; i >= left; -- i) { //bottom
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top; -- i) { //left
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};