//在上坐标排序的情况下，下坐标次序不是从小到大的，则必然不合法（会有相交）。于是，这题就变成了：桥以上坐标从小到大排序后，找出下坐标的最长上升子序列长度
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