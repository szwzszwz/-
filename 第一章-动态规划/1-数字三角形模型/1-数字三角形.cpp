#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510;
int n;
int a[N][N];
int f[N][N];

int main()
{
	// 输入数据
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);

	// 初始化最下行的f数组
	for (int i = 1; i <= n; i++) f[n][i] = a[n][i];

	for (int i = n - 1; i; i--)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i + 1][j] + a[i][j], f[i + 1][j + 1] + a[i][j]);

	printf("%d", f[1][1]);
	return 0;
}