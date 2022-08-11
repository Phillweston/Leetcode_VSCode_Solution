/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 归并思想
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                cur->next = p1;
                cur = cur->next;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                cur = cur->next;
                p2 = p2->next;
            }
        }
        if (p1 = p)
        return dummy->next;
    }
};
// @lc code=end

