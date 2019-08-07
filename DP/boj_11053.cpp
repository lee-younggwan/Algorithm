#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];
int num[1001];
int main()
{
	int i, j;
	int max_num, result;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &num[i]);
	dp[0] = 1;

	for (i = 1; i <= N; i++)
	{
		max_num = 0;
		for (j = 1; j < i; j++)
		{
			if (num[j] < num[i])
			{
				max_num = max(max_num, dp[j]);
			}
		}
		dp[i] = max_num + 1;
	}

	result = 0;
	for(i=0;i<=N;i++)
		result = max(result, dp[i]);
	printf("%d\n", result);

	return 0;
}