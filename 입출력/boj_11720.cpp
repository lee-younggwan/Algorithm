#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i, N;
	string str;
	int sum = 0;

	scanf("%d\n", &N);
	getline(cin, str);

	for (i = 0; i < N; i++)
	{
		sum = sum + str[i] - '0';
	}

	printf("%d\n", sum);

	return 0;
}