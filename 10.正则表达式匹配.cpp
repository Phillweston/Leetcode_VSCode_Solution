/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string a, string b) {
        const char* str = a.c_str();
        const char* pattern = b.c_str();
        // 判断字符串边界
        if (*str == '\0' && *pattern == '\0')
            return true;
        else if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern + 1) != '*') {    //匹配当前字符
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))       // str: any  pattern: .
                return isMatch(str + 1, pattern + 1);
            else {
                return false;
            }
        }
        else {
            if (*str == *pattern || (*str != '\0' && *pattern == '.'))
                // str往后移动几位
                return isMatch(str, pattern + 2) || isMatch(str + 1, pattern);
            else
                return isMatch(str, pattern + 2);
        }
        return true;
    }
};
// @lc code=end

