/**
 * 题意：
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 * 思路：
 * 用string来存新字符串，然后重新赋值回去，用到tring的c_str()函数，复杂度为O(length)
 * 或者要求不引入新字符串的话，计算下新旧位置，从后往前复制就可以
 */
class Solution {
public:
	void replaceSpace(char *str,int length) {
		string s;
        for(int i = 0; i < length; ++ i) {
            if(str[i] == ' ') s += "%20";
            else s += str[i];
        }
        strcpy(str, s.c_str());
	}
};

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int spaceNum = 0, len = strlen(str);
        for (int i = 0; i < len; ++ i) {
            if (str[i] == ' ') {
                spaceNum++;
            }
        }
        int pos1 = len - 1, pos2 = pos1 + 2 * spaceNum;
        str[pos2 + 1] = '\0';
        while(pos1 >= 0) {
            if (str[pos1] == ' ') {
                str[pos2--] = '0';
                str[pos2--] = '2';
                str[pos2--] = '%';
            } else {
                str[pos2--] = str[pos1];
            }
            pos1--;
        }
	}
};