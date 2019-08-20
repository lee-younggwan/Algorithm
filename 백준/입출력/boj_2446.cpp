#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, j;
	int n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++)
			printf(" ");

		for (j = 2 * (n - i - 1); j >= 0; j--)
			printf("*");

		printf("\n");
	}

	for (i = 2; i <= n; i++) {

		for (j = 1; j <= n - i; j++)
			printf(" ");

		for (j = 0; j <= 2 * (i - 1); j++)
			printf("*");

		printf("\n");
	}
	return 0;
}