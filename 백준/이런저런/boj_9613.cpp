#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
int num[101];
int gcd(int a, int b) // 유클리드 호제법(최대공약수를 구함)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int n, t;
	long long int sum;
	scanf("%d", &t);
	for (int test_case = 0; test_case < t; test_case++)
	{
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(num[i], num[j]);
		printf("%lld\n", sum);
		
	}

	return 0;
}