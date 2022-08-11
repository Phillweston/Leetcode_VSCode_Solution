/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // Find函数进行定位时，总是从指定位置开始，返回找到的第一个匹配字符串的位置，而不管其后是否还有相匹配的字符串。
            if (m.find(sum - k) != m.end()) {
                res += m[sum - k];
            }
            m[sum]++;
        }
        return res;
    }
};
// @lc code=end

