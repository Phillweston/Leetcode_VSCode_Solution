/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // 找到前驱节点
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            // 最前面的节点指向null（也就是链表末尾表示）
            cur->next = prev;
            // 前驱节点指向当前节点（反转链表后原前驱节点变为后继节点）
            prev = cur;
            // 当前节点往后移动一位
            cur = next;
        }
        return prev;
    }
};
// @lc code=end

