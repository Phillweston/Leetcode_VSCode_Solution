// 题目：给定一个图像矩阵,以及一个点的坐标和一个阈值,求与点相连的颜色值小于阈值的点的数量
// 方法：广度优先算法
// 思路：使用队列存储点的坐标，并且使用一个二维数组记录点的颜色值，当队列不为空时，取出队列的第一个点，
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 给定的图像矩阵
vector<vector<int>> img = {{37,37,39,41,13,205},
                           {37,41,41,203,39,243},
                           {37,41,40,131,40,41},
                           {91,41,39,198,41,9},
                           {189,41,39,40,40,38},
                           {37,124,38,167,41,41}};
int main() {
    int col = 6, row = 6, x = 2, y = 3, threshold = 3;
    int res = 0;
    if (threshold == 0) {
        cout << "1" << endl;
        return 0;
    }
    else if (threshold == 1) {
        cout << row * col << endl;
        return 0;
    }
    // 初始化访问队列 n*m 的队列并赋值为0
    vector<vector<int>> isVisit(row, vector<int>(col, 0));
    // 每个点相邻的点的相对偏移量
    int array[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int empty = img[x][y];
    // 使用队列记录访问过的点
    queue<pair<int, int>> q;
    q.push({x, y});
    // 初始化刚访问到的点为1
    isVisit[x][y] = 1;
    while (!q.empty()) {
        // pair是将2个数据组合成一组数据，可以使用first和second来访问数据
        // first用于存储二维点的x坐标，second用于存储二维点的y坐标
        pair<int, int> pair = q.front();
        q.pop();
        res ++;
        for (int i = 0; i < 4; i ++) {
            int new_x = pair.first + array[i][0];
            int new_y = pair.second + array[i][1];
            if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col && isVisit[new_x][new_y] == 0 && img[new_x][new_y] < threshold) {
                q.push({new_x, new_y});
                isVisit[new_x][new_y] = 1;
                cout << new_x << " " << new_y << endl;
            }
        }
    }
    cout << res << endl;
    return 0;
}