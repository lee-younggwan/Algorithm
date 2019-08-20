#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long int dp[91];
int N;

int main()
{
	int i;

	dp[1] = 1;
	dp[2] = 1;

	scanf("%d", &N);
	for (i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld\n", dp[N]);
	return 0;
}