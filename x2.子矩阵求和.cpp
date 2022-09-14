/*
给出一个m * n的矩阵a，矩阵元素a[i,j]小于1000，进行q次查询，每次查询给出子矩阵的4个边界（上下左右），求该子矩阵所有元素之和。

样例中第一个查询：1 3 1 2 表示从第1行到第3行，从第1列到第2列，对应的子矩阵是：

1 2
5 6
9 10

求和等于33

Input

第一行2个整数n, m，中间用空格分割，分别对应数组的行数n、列数m(1 <= m,n <= 100) 接下来n行，每行m个整数表示矩阵的内容a[i,j] 。(0 <= a[i,j] <= 1000) 接下来1行，一个数q，对应查询的数量。(1 <= q <= 1000) 接下来q行，每行4个整数，对应矩阵的上下左右边界u,d,l,r。(1 <= u <= d <= n, 1 <= l <= r <= m)

Output

输出共q行，对应q个询问的求和结果。

Sample Input

3 4
1 2 3 4
5 6 7 8
9 10 11 12
3
1 3 1 2
1 2 1 3
1 3 1 3
Sample Output

33
24
54
*/
#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int u, d, l, r;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> d >> l >> r;
        int sum = 0;
        for (int j = u - 1; j < d; j++) {
            for (int k = l - 1; k < r; k++) {
                sum += a[j][k];
            }
        }
        cout << sum << endl;
    }
}