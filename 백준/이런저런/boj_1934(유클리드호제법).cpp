#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b) // ��Ŭ���� ȣ����(�ִ������� ����), a > b
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
		printf("%d\n", temp* A / temp * B / temp); //�ּҰ������ �ִ�����x ������ �ִ������� ��������
	}
	return 0;
}