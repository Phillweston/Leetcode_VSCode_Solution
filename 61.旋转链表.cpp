/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        // 注意该指针的位置
        ListNode* iter = head;
        int count = 1;
        while (iter->next != nullptr) {
            iter = iter->next;
            count++;
        }
        int add = count - k % count;
        if (add == count) return head;
        // 将链表连成环
        iter->next = head;
        // 这里迭代的轮数是add
        while (add--) {
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        // 将环分开
        iter->next = nullptr;
        return ret;
    }
};
// @lc code=end

