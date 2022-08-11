/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        // 保存k中的index
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 当队列不为空且队列头元素小于当前元素时，弹出队列头元素
            while (!q.empty() && nums[q.front()] < nums[i]) q.pop_front();
            // 当队列不为空且队列尾元素小于当前元素时，弹出队列尾元素
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            // 当队列为空或者队列尾元素大于当前元素时，将当前元素放入队列尾部
            q.push_back(i);
            // 当队列长度大于等于k时，将队列头元素弹出
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end

