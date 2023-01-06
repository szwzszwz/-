#include<iostream>
#include<vector>
using namespace std;

int stairs(int n)
{	
	// 定义变长二维数组
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	
	// 初始化
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = dp[2][1] = 1;
	
	// 循环
	for(int i = 3;i <= n;i++){
		// 递推公式
		dp[i][0] = dp[i - 1][1] + dp[i - 2][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 2][0];
	}
	
	return dp[39][0];
}

int main()
{
	int n = stairs(39);
	printf("n = %d",n);
	return 0;
}