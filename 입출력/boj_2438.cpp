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
		for (j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}