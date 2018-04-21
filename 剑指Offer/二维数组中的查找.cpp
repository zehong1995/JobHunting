class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x = (int)array.size() - 1;
        int y = 0;
        while(x >= 0 && y < array[x].size()) {
            if (target == array[x][y]) {
                return true;
            } else if (target > array[x][y]) {
                y++;
            } else {
                x--;
            }
        }
        return false;
    }
};
/*
题意：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：
因为保证严格递增，所以可以从左下角出发
target大于当前值，则右移，
target小于当前值，则上移
target等于当前值，则返回true
注意边界问题，因为这是一个vector动态数组，不一定保证列数固定
复杂度为O(n+m)

*/
