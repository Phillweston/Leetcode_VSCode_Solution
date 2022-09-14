/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        // 有效字符串的长度一定是偶数
        // 用一个栈来存储左括号
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char topChar = stk.top();
                stk.pop();
                if (topChar == '(' && ch != ')') {
                    return false;
                }
                if (topChar == '[' && ch != ']') {
                    return false;
                }
                if (topChar == '{' && ch != '}') {
                    return false;
                }
            }
        }
    }
};
// @lc code=end

