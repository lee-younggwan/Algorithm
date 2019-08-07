#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100001];
int num[100001];
int main()
{
	int i;
	int result;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &num[i]);
	dp[1] = num[1];

	// i��°�� dp[i-1]+num[i]�� ���� num[i]�� ���� ������ �� ū ��
	for (i = 2; i <= N; i++)
		dp[i] = max(dp[i - 1] + num[i], num[i]);

	result = -1001;
	for(i=1;i<=N;i++)
		result = max(result, dp[i]);

	printf("%d\n", result);

	return 0;
}