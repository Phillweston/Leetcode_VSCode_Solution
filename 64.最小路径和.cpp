/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 当前单元格只能从左方单元格或上方单元格走到，因此只需要考虑矩阵左边界和上边界。
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // 当左边和上边都是矩阵边界时
                if (i == 0 && j == 0) continue;
                // 当只有左边是矩阵边界时
                else if (i == 0) grid[i][j] += grid[i][j - 1];
                // 当只有上边是矩阵边界时
                else if (j == 0) grid[i][j] += grid[i - 1][j];
                // 当左边和上边都不是矩阵边界时
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }
};
// @lc code=end

