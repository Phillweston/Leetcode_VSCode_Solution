/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        // 递归思想
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        // 如果左右子树都不为空，说明这个节点就是最近公共祖先
        if (left && right) return root;
        // 如果左子树不为空，说明这个节点就是最近公共祖先
        if (left) return left;
        // 如果右子树不为空，说明这个节点就是最近公共祖先
        return right;
    }
};
// @lc code=end

