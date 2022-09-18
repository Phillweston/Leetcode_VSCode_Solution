/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        // 1. 从起点到终点的最小代价
        int maxCost = 1e9;
        int m = rowCosts.size(), n = colCosts.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, maxCost));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + rowCosts[i - 1];
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + colCosts[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j] + rowCosts[i - 1], dp[i][j - 1] + colCosts[j - 1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

