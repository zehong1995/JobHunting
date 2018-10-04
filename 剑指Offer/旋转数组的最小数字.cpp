/**
 * 旋转数组的最小数字
 * 题意：
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 * 思路：
 * 二分，因为旋转，且不递减序列，那么a[last] <= a[first]
 * 于是可以分三种情况：
 * num[mid] < num[low]; 那么最小元素一定在mid左侧，high=mid
 * num[mid] > num[high]; 那么最小元素一定在mid右侧,low=mid
 * 否则的话，结合a[last] <= a[first]，那么a[mid]==a[low]&&a[mid]==a[high]，此时无法判断，所以low++,high--
 * 此方法不可用在顺序数组，但题目说了是旋转，所以不用特判
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n = rotateArray.size();
        if(n == 0) {
            return 0;
        }
        int low = 0, high = n - 1;
        while(low + 1 < high) {
            int mid = low + high >> 1;
            if(rotateArray[mid] < rotateArray[low]) {
                high = mid;
            } else if (rotateArray[mid] > rotateArray[high]) {
                low = mid;
            } else {
                low++;
                high--;
            }
        }
        return rotateArray[high];
    }
};