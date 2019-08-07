#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[11];

int main()
{
	int T, n, test_case, i;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &n);
		for (i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n]);

	}

	return 0;
}