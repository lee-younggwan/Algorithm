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
	dp[2] = 3;

	scanf("%d", &n);

	// i-1번째에서 1x2 한개붙이는 경우 + i-2번째에서 2x1 두개 붙이는 경우 + 2x2 한개붙이는 경우
	for (i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]*2) % 10007; 
	}
	printf("%d\n", dp[n]);

	return 0;
}