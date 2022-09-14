/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 哈希表方法，先找到连续序列的起点，然后从起点开始遍历，直到下一个点在哈希表中不存在
        unordered_set<int> num_set;
        for (int num : nums) {
            num_set.insert(num);
        }
        int longest_streak = 0;
        for (int num : num_set) {
            // 如果当前数字的前一个数字在哈希表中，说明当前数字不是连续序列的起点，跳过
            if (num_set.find(num - 1) != num_set.end()) {
                continue;
            }
            // 如果当前数字的前一个数字不在哈希表中，说明当前数字是连续序列的起点
            int current_num = num;
            int current_streak = 1;
            // 从当前数字开始，不断尝试寻找下一个数字
            while (num_set.find(current_num + 1) != num_set.end()) {
                current_num += 1;
                current_streak += 1;
            }
            // 更新最长连续序列的长度
            longest_streak = max(longest_streak, current_streak);
        }
    }
};
// @lc code=end

