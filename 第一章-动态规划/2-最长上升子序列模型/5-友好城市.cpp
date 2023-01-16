//�����������������£�����������Ǵ�С����ģ����Ȼ���Ϸ��������ཻ�������ǣ�����ͱ���ˣ������������С����������ҳ������������������г���
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 5010;
int n;
int f[N];
PII q[N];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> q[i].first >> q[i].second;
	sort(q, q + n);
	int res = 0;
	for (int i = 0; i < n; i++) {
		f[i] = 1;
		for (int j = 0; j < i; j++)
			if (q[j].second < q[i].second)
				f[i] = max(f[i], f[j] + 1);
		res = max(res, f[i]);
	}
	cout << res;
	return 0;
}