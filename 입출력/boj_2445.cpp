#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, N;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
			printf("*");
		for (j = 1; j <= 2 * N - 2 * i; j++)
			printf(" ");
		for (j = 2 * N - i; j <= 2 * N - 1; j++)
			printf("*");

		printf("\n");
	}
	for (i = N - 1; i >= 1; i--)
	{
		for (j = i; j >= 1; j--)
			printf("*");
		for (j = 2 * N - 2 * i; j >= 1; j--)
			printf(" ");
		for (j = 2 * N - 1; j >= 2 * N - i; j--)
			printf("*");

		printf("\n");
	}
	
	return 0;
}