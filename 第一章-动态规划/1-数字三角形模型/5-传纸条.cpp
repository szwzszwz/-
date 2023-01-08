#include<iostream>
#include<algorithm>

using namespace std;

const int N = 55;
int n, m;
int w[N][N];
int f[N * 2][N][N];

int main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    for (int k = 2; k <= n + m; k++) // k = i1 + j1 = i2 + j2
        // 循环内部判断推导如下
        // 1 <= x1 <= n, 1 <= k - x1 <= m,
        // 1 <= x1 <= n, x1 <= k - 1, x1 >= k - m
        // x1 <= n 且 x1 <= k - 1  &&  x1 >= 1 且 x1 >= k - m
        // x1 <= min(n, k - 1)  &&  x1 >= max(1, k - m)
        for (int i1 = max(1, k - m); i1 <= min(k - 1, n); i1++)
            for (int i2 = max(1, k - m); i2 <= min(k - 1, n); i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m) {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2 - 1] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - 1][i2] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2 - 1] + t);
                    f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1][i2] + t);
                }
            }

    cout << f[n + m][n][n];
    return 0;
}