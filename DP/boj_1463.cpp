#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001];

int main()
{
	int X;
	int i;
	dp[1] = 0;
	dp[2] = 1;

	scanf("%d", &X); //X는 1~10^6

	for (i = 3; i <= X; i++)
	{
		dp[i] = dp[i - 1] + 1; // dp[i-1을 1로 만드는 최소 횟수] + 1
		if (i % 2 == 0) // 2로 나누어 진다면
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	printf("%d\n", dp[X]);

	return 0;
}