// 很重要的集合划分依据：“最后”
// 集合划分原则：不重复（求数量要求，求最大/最小时不要求），不遗漏


#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
int n, m;
int w[N][N];
int f[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--) {
		// 初始化
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> w[i][j];

		// dp运算
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];

		cout << f[n][m] << endl;
	}

	return 0;
}