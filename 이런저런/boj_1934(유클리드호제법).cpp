#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b) // 유클리드 호제법(최대공약수를 구함), a > b
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
	int n;
	int A, B, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &A, &B);

		if (B > A)
		{
			temp = B;
			B = A;
			A = temp;
		}
		temp = gcd(A, B);
		printf("%d\n", temp* A / temp * B / temp); //최소공배수는 최대공약수x 값들을 최대공약수로 나눈값들
	}
	return 0;
}