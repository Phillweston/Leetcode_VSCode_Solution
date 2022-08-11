/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    // 双指针法
    int maxArea(vector<int>& height) {
        // 双指针代表的是可以作为容器边界的所有位置的范围
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            // 求当前容器的容积
            int area = min(height[l], height[r]) * (r - l);
            // 对比当前容器的容积和上一次的容器的容积
            ans = max(ans, area);
            // 左指针高度较小则移动左指针，否则移动右指针
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
// @lc code=end

