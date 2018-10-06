/**
 * 题目：
 * 表示数值的字符串
 * 题意：
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 * 思路：
 * 多种做法，明确思路后模拟。注意AC可以带正负号，而B不可以带正负号
 */

//匹配A[.[B]][e|EC] 或者 .B[e|EC]
//剑指offer的做法
class Solution {
public:
    bool isNumeric (const char * string) {
        if (string == nullptr) {
            return false;
        }
        bool flag = scanInteger(&string);
        if (*string == '.') {
            ++string;
            flag |= scanUnsignedInteger(&string);
        }
        if (*string == 'e' || *string == 'E') {
            ++string;
            flag &= scanInteger(&string);
        }
        flag &= *string == '\0';
        return flag;
    }
    bool scanInteger(const char** string) {
        if (**string == '+' || **string == '-') {
            (*string)++;
        }
        return scanUnsignedInteger(string);
    }
    bool scanUnsignedInteger(const char** string) {
        bool flag = false;
        while(**string != '\0' && isdigit(**string)) {
            ++(*string);
            flag = true;
        }
        return flag;
    }
};


//处理非数字部分，拆分后剩余部分一定得是数字
class Solution {
public:
    bool isNumeric(char* string)
    {
        int n = strlen(string);
        if(n == 0) {
            return false;
        }
        int idx = 0;
        if(string[idx] == '+' || string[idx] == '-') {
            idx++;
        }
        if(string[idx] == '+' || string[idx] == '-') {
            return false;
        }
        int cnt = 0;
        while(idx < n) {
            if(tolower(string[idx]) == 'e') {
                if(idx == n - 1) {
                    return false;
                }
                idx++;
                break;
            } else if(string[idx] == '.') {
                cnt++;
                if(cnt > 1) {
                    return false;
                }
            } else if(!isdigit(string[idx])) {
                return false;
            }
            idx++;
        }
        if(idx < n && (string[idx] == '+' || string[idx] == '-')) {
            idx++;
        }
        while(idx < n) {
            if(!isdigit(string[idx])) {
                return false;
            }
            idx++;
        }
        return true;
    }

};


