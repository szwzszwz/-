// ����Ҫ�ļ��ϻ������ݣ������
// ���ϻ���ԭ�򣺲��ظ���������Ҫ�������/��Сʱ��Ҫ�󣩣�����©


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
		// ��ʼ��
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> w[i][j];

		// dp����
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];

		cout << f[n][m] << endl;
	}

	return 0;
}