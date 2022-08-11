/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) return false;
        // 26个字母每个对应一个位置，初始化为0
        // 'z'对应的ASCII码值为122
        vector<int> count(26, 0);
        // 字符匹配判断
        for (int i = 0; i < len1; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (check(count)) return true;
        for (int i = len1; i < len2; i++) {
            count[s2[i] - 'a']++;
            count[s2[i - len1] - 'a']--;
            if (check(count)) return true;
        }
        return false;
    }
    bool check(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
// @lc code=end

