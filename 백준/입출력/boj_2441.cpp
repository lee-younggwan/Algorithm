#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j, N;
	scanf("%d", &N);

	for (i = N; i >= 1; i--)
	{
		for (j = N; j > i; j--)
			printf(" ");
		for (j = i; j >= 1; j--)
			printf("*");
		printf("\n");
	}

	return 0;
}