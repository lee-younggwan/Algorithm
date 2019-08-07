#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
long long int dp[101] = {0,1,1,1,2,2};
int main()
{
	int i, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);

		for (i = 6; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		printf("%lld\n", dp[N]);
	}
	return 0;
}