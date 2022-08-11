/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    // 思路：优先队列+BFS
    struct node {
        int x, y, t;
        node(int m_x = 0, int m_y = 0, int m_t = 0) : x(m_x), y(m_y), t(m_t) {}
        bool operator<(const node& a) const { 
            return t > a.t;
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 初始化访问矩阵
        bool vis[110][110] = {0};
        // 初始化方向代价矩阵
        // 方向为{下，右，上，左}
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        // 矩阵的行数
        int ex = heights.size();
        // 矩阵的列数
        int ey = heights[0].size();
        priority_queue<node> p;
        p.push(node(0, 0, 0));
        while (!p.empty()) {
            node temp = p.top();
            p.pop();
            if (vis[temp.x][temp.y]) continue;
            vis[temp.x][temp.y] = 1;
            if (temp.x == ex - 1 && temp.y == ey - 1) {
                // x移动的距离为矩阵的行数，y移动的距离为矩阵的列数，找到答案
                return temp.t;
            }
            int xx, yy, zz;
            for (int i = 0; i < 4; i++) {
                xx = temp.x + dx[i];
                yy = temp.y + dy[i];
                // 判断条件：代价值大于等于0，代价值未超出边界，未出现重复访问节点
                if (xx >= 0 && yy >= 0 && xx < ex && yy < ey && vis[xx][yy] == 0) {
                    zz = abs();
                }
            }
        }
    }
};
// @lc code=end

