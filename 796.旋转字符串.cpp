/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        string s_new;
        if (s.size() != goal.size()) return false;
        if (s == goal) return true;
        for (int i = 1; i < s.size(); i ++) {
            // 从s字符串第i位开始截取，判断是否与goal相等
            s_new = s.substr(i);
            for (int j = 0; j < i; j ++) {
                s_new += s[j];
            }
            // cout << s_new << endl;
            if (s_new == goal) return true;
        }
        return false;
    }
};
// @lc code=end

