/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;
        // Lambda表达式形式：[capture](parameters)->mutable{return-type}
        auto cmp = [&num1, &num2](const pair<int, int>& a, const pair<int, int>& b) {
            return num1[a.first] + num2[a.second] > num1[b.first] + num2[b.second];
        };
        // 保存k中的index
        // pair作用：将2个数据组合成一组数据
        // 没有显示初始化，自动执行默认初始化操作。q为(0, 0)
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(cmp);
        for (int i = 0; i < min(k, nums1.size()); i++) {
            // 将nums1的前k个索引数对加入到pq队列中
            // 这里emplace_back作用类似push_back，但是可以不需要拷贝或者移动内存，相比push_back能更好地避免内存的拷贝与移动，使容器插入元素的性能得到进一步提升。
            pq.emplace_back(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            // 从队列中取出元素时，将num2的索引增加
            auto [x, y] = pq.top();
            pq.pop();
            res.push_back({nums1[x], nums2[y]});
            if (y + 1 < nums2.size()) {
                pq.emplace_back(x, y + 1);
            }
        }
        return res;
    }
};
// @lc code=end

