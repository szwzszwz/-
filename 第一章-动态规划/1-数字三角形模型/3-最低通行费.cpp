// �� 2N-1 �����Ƴ� �����߻�ͷ·

// ����һ��ͨ���ж��Ƿ�Ϊ�߽磬������ѡ��
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110,INF = 1e9;
int n;
int w[N][N];
int f[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == 1 && j == 1) f[i][j] = w[i][j];
			else {
				f[i][j] = INF;
				if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
				if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
			}
	
	cout << f[n][n] << endl;
	return 0;
}

// �����������߽�������г�ʼ�����ܿ��ж���
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110, INF = 1e9;
int n;
int w[N][N];
int f[N][N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];

	for (int i = 0; i <= n; i++) {
		f[i][0] = INF;
		f[0][i] = INF;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1)
				continue;
			f[i][j] = min(f[i][j - 1], f[i - 1][j]) + w[i][j];
		}

	cout << f[n][n] + w[1][1] << endl; // ©���һ�����ִ�С
	return 0;
}