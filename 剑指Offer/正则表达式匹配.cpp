/**
 * 题目：
 * 正则表达式
 * 题意：
 * 请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
 * 而'*'表示它前面的字符可以出现任意次（包含0次）。 
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 * 思路：
 * 构建模式串的有限状态机，例如ba*ab的有限状态机如下：
 * 1 -> b -> 2
 * 2 -> a -> 2
 * 2 -> a -> 3
 * 3 -> b -> 4
 * 所以当出现*的时候存在三种情况，接受+保持当前状态；接受+转移下一状态；拒绝+转移下一状态
 * 其余情况简单匹配下就可以
 */
 
class Solution {
public:
    bool match(char* str, char* pattern) {
        if (str == nullptr || pattern == nullptr) {
            return false;
        } else {
            return dfsMatch(str, pattern);
        }
    }
    bool dfsMatch(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        //str can be an empty string
        //such as "" and ".*", they are matched
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }
        if (*(pattern + 1) == '*') {
            if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
                return dfsMatch(str + 1, pattern)     // accepted and stay on the current state
                    || dfsMatch(str + 1, pattern + 2) // accepted and jump to the next state
                    || dfsMatch(str, pattern + 2);    // rejected and jump to the next state
            } else {
                return dfsMatch(str, pattern + 2); //rejected and jump to the next state
            }
        } else if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return dfsMatch(str + 1, pattern + 1);
        }
        return false;
    }
};