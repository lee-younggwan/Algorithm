#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

long long int gcd(long long int a, long long int b) // 유클리드 호제법(최대공약수를 구함), a > b
{
	long long int c;
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
	int n;
	long long int A, B, temp;
	
		scanf("%lld %lld", &A, &B);

		if (B > A)
		{
			temp = B;
			B = A;
			A = temp;
		}
		temp = gcd(A, B);
		for (int i = 0; i < temp; i++)
			printf("1");
	
	return 0;
}