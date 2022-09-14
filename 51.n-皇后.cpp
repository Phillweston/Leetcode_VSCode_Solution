/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> backtrack(vector<vector<string>>& res, vector<string>& board, int row) {
        // 如果row等于board的行数，说明已经找到了一个解
        if (row == board.size()) {
            res.push_back(board);
            return res;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            // 如果当前位置不合法，跳过
            if (!isValid(board, row, col)) continue;
            // 做选择
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(res, board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        // 如果在同一行、同一列或者同一对角线上，那么就是同一个皇后，会互相攻击
        if (n < 1) return {};
        vector<vector<string>> res;
        // 初始化方格棋盘，vector中的每个元素都是一个string，表示一行
        vector<string> board(n, string(n, '.'));
        return backtrack(res, board, 0);
    }
};
// @lc code=end

