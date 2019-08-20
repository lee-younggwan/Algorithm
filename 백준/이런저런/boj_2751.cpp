#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[1000001];
int main()
{
	int i;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	sort(num,num+N);
	for (i = 0; i < N; i++)
		printf("%d\n", num[i]);

	return 0;
}