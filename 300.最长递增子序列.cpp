/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int max_subsequences(vector<int>& arr, vector<int>& dp) {
        int max_len = 0;
        for (int i = 0; i < arr.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // 找出已知的max_len与当前dp[i]的最大值
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        // dp[i]表示以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 从0到i-1中所有比arr[i]小的数中，都可以作为倒数第二个数
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return max_subsequences(nums, dp);
    }
};
// @lc code=end

