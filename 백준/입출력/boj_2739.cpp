#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i;
	
	scanf("%d", &N);

	for (i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", N, i, N*i);
	}

	return 0;
}