#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int pack[1001];
int main()
{
	int i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &pack[i]);
	dp[0] = 0;
	pack[0] = 0;

	for (i = 1; i <= N; i++) 
	{
		dp[i] = -1;;

		for (j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + pack[j]);
		}
	}

	printf("%d\n", dp[N]);
	return 0;
}