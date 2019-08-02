#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i;
	int sum = 0;
	
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		sum = sum + i;
	}
	printf("%d", sum);

	return 0;
}