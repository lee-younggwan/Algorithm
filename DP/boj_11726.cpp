#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main()
{
	int i, n;
	dp[1] = 1;
	dp[2] = 2;
	
	scanf("%d", &n);

	for (i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	printf("%d\n", dp[n]);

	return 0;
}