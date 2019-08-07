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

	// i-1��°���� 1x2 �Ѱ����̴� ��� + i-2��°���� 2x1 �ΰ� ���̴� ��� + 2x2 �Ѱ����̴� ���
	for (i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]*2) % 10007; 
	}
	printf("%d\n", dp[n]);

	return 0;
}