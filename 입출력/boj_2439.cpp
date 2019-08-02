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
		for (j = 0; j < N-i; j++)
			printf(" ");
		for (j = N - i; j < N; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}