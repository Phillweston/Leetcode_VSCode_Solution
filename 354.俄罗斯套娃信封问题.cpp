/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 参考：最长递增子序列
        // 1. 先对信封进行排序，按照宽度升序排列，如果宽度一样，按照高度降序排列
        // 2. 对高度数组寻找最长递增子序列的长度
        // 3. 最长递增子序列的长度就是最多能套娃的信封数
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
    }
};
// @lc code=end

