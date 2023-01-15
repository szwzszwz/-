/*
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1010;
int n;
int a[N], f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	printf("%d\n", res);
	return 0;
}
*/

#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010;
int n;
int a[N];
int q[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int len = 0;	
	q[0] = -2e9;
	for (int i = 0; i < n; i++)
	{
		int l = 0, r = len;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	printf("%d", len);
	return 0;
}