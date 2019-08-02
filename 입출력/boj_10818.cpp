#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, i, temp;
	int min = 1000001;
	int max = -1000001;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		if (temp < min)
			min = temp;
		if (temp > max)
			max = temp;
	}

	printf("%d %d", min, max);

	return 0;
}